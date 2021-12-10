//Bibliotheken importieren
#include "WiFi.h"
#include "ESPAsyncWebServer.h"

//eigene Funktionen und globale Variablen importieren
#include "ADCSetup.h"
#include "ServerSetup.h"
#include "readCurrentandPuls.h"
#include "serialOut.h"
#include "tachometer.h"
#include "variables.h"


TaskHandle_t Task1;

int loops = 0;

void setup() {
  delay(200);

  setCpuFrequencyMhz(240);    //CPU Frequenz auf 240MHz stellen

  //Ein- und Ausgänge setzen
  pinMode(currentPin1, INPUT);
  pinMode(currentPin2, INPUT);
  pinMode(pulsPin1, INPUT);
  pinMode(pulsPin2, INPUT);
  pinMode(steuerInputPin, INPUT);
  pinMode(pedalPin, INPUT);
  pinMode(bremsPin1, INPUT);
  pinMode(bremsPin2, INPUT);

  pinMode(steuerOutputPin1, OUTPUT);
  pinMode(steuerOutputPin2, OUTPUT);
  pinMode(loopTimingPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  digitalWrite(loopTimingPin, LOW);

  manualAdcSetup();

  Serial.begin(115200);  // Serial port for debugging purposes
  Serial.println();
  Serial.print("CPU-Frequency: ");
  Serial.print(getCpuFrequencyMhz());
  Serial.println("MHz");
  delay(100);
  Serial.printf("Main running on Core %d\n ", xPortGetCoreID());
  Serial.println();
  delay(100);
  taskSetup();

  delay(4000);
}

void loop() {
  digitalWrite(loopTimingPin, HIGH);
  digitalWrite(ledPin, puls1);    //bereinigter Magnetsensor Output
  
  readSpeed();
  current1 = readCurrent(currentPin1, currentCal1, shunt1);
  current2 = readCurrent(currentPin2, currentCal2, shunt2);
  puls1 = readPulse(pulsPin1);
  puls2 = readPulse(pulsPin2);
  
  if (loops >= 20) { //nur alle 20 Durchgänge serielle Ausgabe
    serialOutput();
    loops = 0;
  } else {
    ++loops;
  }
  
  digitalWrite(loopTimingPin, LOW);
  
}



void taskSetup() {
  xTaskCreatePinnedToCore(
    serverSetup,
    "Task1",
    64000,
    NULL,
    3,
    &Task1,
    0);
}
