//Bibliotheken importieren
#include "WiFi.h"
#include "ESPAsyncWebServer.h"

//eigene Funktionen und globale Variablen importieren
#include "ADCSetup.h"
#include "ControlLoop.h"
#include "SDSetup.h"
#include "ServerSetup.h"
#include "serialOut.h"
#include "variables.h"




TaskHandle_t ControlLoop;
TaskHandle_t ServerTask;
TaskHandle_t SDTask;


void setup() {
  delay(200);

  setCpuFrequencyMhz(240);    //CPU Frequenz auf 240MHz stellen

  //Ein- und Ausgänge setzen
  pinMode(voltagePin, INPUT);
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
  pinMode(debugTimingPin, OUTPUT);

  digitalWrite(debugTimingPin, LOW);

  manualAdcSetup();

  Serial.begin(115200);  // Serial port for debugging purposes
  Serial.println();
  Serial.println();
  Serial.print("CPU-Frequency: ");
  Serial.print(getCpuFrequencyMhz());
  Serial.println("MHz");
  Serial.println();
  delay(100);
  Serial.printf("Main running on Core %d\n ", xPortGetCoreID());
  delay(100);
  taskSetup();

  delay(4000);
}

void loop() {
  //digitalWrite(debugTimingPin, !digitalRead(debugTimingPin));
  serialOutput();
  vTaskDelay(pdMS_TO_TICKS(25));
}



void taskSetup() {

  xTaskCreatePinnedToCore(
    controlLoop,          //Funktionsname
    "ControlLoop",        //Name fuer Debug
    64000,                //Groesse des Stacks
    NULL,                 //Parameter
    12,                   //Prioritaet, kleiner = unwichtiger
    &ControlLoop,         //Task handle
    0);                   //Kern

  delay(100);             //Pause zum starten des Tasks
 
  xTaskCreatePinnedToCore(
    sdSetup,              //Funktionsname
    "SDTask",             //Name fuer Debug
    64000,                //Groesse des Stacks
    NULL,                 //Parameter
    4,                    //Prioritaet
    &SDTask,              //Task handle
    1);                   //Kern

  delay(100);             //Pause zum starten des Tasks

  xTaskCreatePinnedToCore(
    serverSetup,          //Funktionsname
    "ServerTask",         //Name fuer Debug
    64000,                //Groesse des Stacks
    NULL,                 //Parameter
    4,                    //Prioritaet, kleiner = unwichtiger
    &ServerTask,          //Task handle
    1);                   //Kern, Kern1 standardmaessig fuer Loop, Kern0 also frei

}
