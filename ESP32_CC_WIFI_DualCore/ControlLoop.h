#include "variables.h"
#include "tachometer.h"
#include "readInputs.h"

void controlLoop( void * parameter ){
  delay(100);
  Serial.printf("ControlLoop running on Core %d\n ", xPortGetCoreID());
  TickType_t xLastWakeTime;
  while(true){
    //digitalWrite(debugTimingPin, !digitalRead(debugTimingPin));
    digitalWrite(debugTimingPin, HIGH);           //insgesamt ~175us
    readSpeed();
    voltage = readVoltage_Avg(voltagePin, volBuffer, buffer_length, &cur1Buffer_i, voltageCal);
    voltage = readVoltage_Avg(voltagePin, volBuffer, buffer_length, &cur1Buffer_i, voltageCal);
    voltage = readVoltage_Avg(voltagePin, volBuffer, buffer_length, &cur1Buffer_i, voltageCal);
    //digitalWrite(debugTimingPin, HIGH);
    current1 = readCurrent_Avg(currentPin1, cur1Buffer, buffer_length, &cur1Buffer_i, currentCal1, shunt1);
    //digitalWrite(debugTimingPin, LOW);
    current2 = readCurrent_Avg(currentPin2, cur2Buffer, buffer_length, &cur2Buffer_i, currentCal2, shunt2);
    puls1 = readPulse(pulsPin1);
    puls2 = readPulse(pulsPin2);
    digitalWrite(debugTimingPin, LOW);
    
    vTaskDelayUntil( &xLastWakeTime, pdMS_TO_TICKS(1) );    //warten bis insgesamt 1000us vergangen sind --> 1000Hz unabhaengig davon wie lange der Loop braucht, solange unter 1000us
  }
}
