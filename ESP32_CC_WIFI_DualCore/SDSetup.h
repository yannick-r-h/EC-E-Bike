#include <SPI.h>
#include <SD.h>
#include "variables.h"

void sdSetup( void * parameter ){
  delay(10);
  Serial.printf("SD Output running on Core %d\n ", xPortGetCoreID());
  SPI.begin(VSPI_SCK,VSPI_MISO,VSPI_MOSI,VSPI_SS);


  textFile = SD.open(fileName, FILE_APPEND);
  if(textFile){
    Serial.println("Textdatei geoeffnet!");  
  } else {
    Serial.println("Konnte Datei nicht oeffnen, beende SDTask!");
    vTaskDelete( NULL );
  }
  
  while(1){
    if(puls1){
      //digitalWrite(debugTimingPin, !digitalRead(debugTimingPin));
      textFile.printf("%lu,%f,%f,%f,%f",millis(),velocity,voltage,current1,current2);
      textFile.close();
    }
    vTaskDelay(pdMS_TO_TICKS(10));
  }
  vTaskDelete( NULL );
}


//Zeit seit Beginn einspeichern als Timecode für Messwerte; Jedes mal ausgeben wenn Puls kommt
