#include "variables.h"
#include "tachometer.h"
#include "readInputs.h"

void controlLoop( void * parameter ){
  vTaskDelay(100);
  Serial.printf("measureLoop running on Core %d\n ", xPortGetCoreID());
  TickType_t xLastWakeTime;
  int i = 0;
  int j=0;
  while(true){
    
    digitalWrite(debugTimingPin1, !digitalRead(debugTimingPin1));
    if(i >=25){
      digitalWrite(debugTimingPin2, !digitalRead(debugTimingPin2));
      //digitalWrite(debugTimingPin1, HIGH);           //insgesamt ~175us
      voltage = read_Avg(voltagePin, volBuffer, buffer_length, &cur1Buffer_i, voltageCal);
      //digitalWrite(debugTimingPin1, HIGH);
      current1 = read_Avg(currentPin1, cur1Buffer, buffer_length, &cur1Buffer_i, currentCal1, shunt1);
      //digitalWrite(debugTimingPin1, LOW);
      current2 = read_Avg(currentPin2, cur2Buffer, buffer_length, &cur2Buffer_i, currentCal2, shunt2);
  
      brems1 = read_Avg(bremsPin1, brems1Buffer, buffer_length, &brems1Buffer_i);
      brems2 = read_Avg(bremsPin2, brems2Buffer, buffer_length, &brems2Buffer_i);
      
      //dacWrite(steuerOutputPin1, steuerOut1);
      dacWrite(steuerOutputPin1, steuerOut2);

      i = 0;
    } else {
      ++i;
    }
    dacWrite(steuerOutputPin1, (128+127*sin((2*3.14159265359*j)/4096)));
    dacWrite(steuerOutputPin2, (64-63*sin((2*3.14159265359*j)/4096)));
    if(j>=4095){
      j=0;
    }else{
      ++j;
    }
    
    prePuls1 = puls1;
    prePuls2 = puls2;
    puls1 = readPulse(pulsPin1);
    puls2 = readPulse(pulsPin2);
    readSpeed(puls1, prePuls1, pulsStart1, pulsStop1, pulsTime1, &velocity);
    readSpeed(puls2, prePuls2, pulsStart2, pulsStop2, pulsTime2, &controlVelocity);
    
    //digitalWrite(debugTimingPin1, LOW);
    
    vTaskDelayUntil( &xLastWakeTime, pdMS_TO_TICKS(1) );    //warten bis insgesamt 1000us vergangen sind --> 1000Hz unabhaengig davon wie lange der Loop braucht, solange unter 1000us
  }
}
