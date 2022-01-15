#include "variables.h"


void readSpeed() {


  if (prePuls == 0 && puls1 == 1) {
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
      velocity = (circumference / timeSum) * 1000000;
    } else {
      velocity = 0;
    }

  }


  prePuls = puls1;
}
