#include "variables.h"

//Funktioniert nicht (Velocity meist Null), aktualisiert nur bei Pulsen --> gibt theoretisch auch bei Stillstand noch vorherige Geschwindigkeit aus


void readSpeed(bool puls, bool prePuls, uint32_t& pulsStart, uint32_t& pulsStop,uint32_t pulsTime[], float *velocity_p) {


  if (prePuls == 0 && puls == 1) {
    
    pulsStop = micros();
    uint32_t temp = pulsStop - pulsStart;
    pulsStart = micros();
    
    for (int i = 0; i < 8; ++i) {
      pulsTime[8 - i] = pulsTime[7 - i];
    }
    pulsTime[0] = temp;
    
    int timeSum = 0;
    for (int i = 0; i < 9; ++i) {
      timeSum += pulsTime[i];
    }
    
    if (timeSum != 0) {
      *velocity_p = ((circumference * 1000000.0) / timeSum);
    } else {
      *velocity_p = 0;
    }

  } else if ((micros()-pulsStart)>= 1000000) {    //Wenn seit letztem Puls mehr als 1s vergangen sind Velocity auf Null setzen
    *velocity_p = 0;
    for(int i=0; i<9; ++i){
      pulsTime[i] = UINT32_MAX;                   //Alle Werte auf Maximalwert setzen, damit Geschwindigkeit von Null beginnt
    }
  }


  prePuls = puls;
}
