#include "variables.h"

void readCurrent1() {
  current1intermediate = 0;
  for (int i = 0; i<= measurements; i++) {
      current1intermediate = (current1intermediate + (analogRead(currentPin1)));
  }
  current1 = (current1intermediate / (measurements * cal1 * shunt1)); 
}

void readCurrent2() {
  current2intermediate = 0;
  for (int i = 0; i<= measurements; i++) {
      current2intermediate = (current2intermediate + (analogRead(currentPin2)));
  }
  current2 = (current2intermediate / (measurements * cal2 * shunt2)); 
}

void readPulseTime() {
  pulsIntermediate = 0;
  for (int i = 0; i<= measurements; i++) {
      pulsIntermediate = (pulsIntermediate + (analogRead(pulsPin)));
  }
  pulsAnalog = (pulsIntermediate / measurements);

  if (pulsAnalog > 3500) { //oberer Schwellwert fuer Aenderung 
    puls = 1;
  }
  else if (pulsAnalog < 2600) { //unterer Schwellwert fuer Aenderung
    puls = 0;  
  }
}
