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
  pinMode(ledPin, OUTPUT);
  pinMode(loopTimingPin, OUTPUT);
  pinMode(currentPin1, INPUT);
  pinMode(currentPin2, INPUT);
  pinMode(pulsPin, INPUT);
  pinMode(steuerInputPin, INPUT);

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
  digitalWrite(ledPin, puls);    //bereinigter Magnetsensor Output
  readSpeed();
  readCurrent1();
  readCurrent2();
  readPulseTime();
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
