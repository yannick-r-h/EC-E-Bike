#include "variables.h"

double readCurrent(const byte pin, const double cal, const double shunt) {
  uint64_t currentintermediate = 0;
  for (int i = 0; i <= measurements; i++) {
    currentintermediate = (currentintermediate + (analogRead(pin)));
  }
  return (double)(currentintermediate / (measurements * cal * shunt));
}


bool readPulse(const byte pin) {
  uint64_t pulsIntermediate = 0;
  for (int i = 0; i <= measurements; i++) {
    pulsIntermediate = (pulsIntermediate + (analogRead(pin)));
  }
  uint32_t pulsAnalog = (pulsIntermediate / measurements);

  if (pulsAnalog > 3500) { //oberer Schwellwert fuer Aenderung
    return 1;
  }
  else if (pulsAnalog < 2600) { //unterer Schwellwert fuer Aenderung
    return 0;
  }
  else {
    if(pin == pulsPin1){
      return puls1;  
    } else {
      return puls2;
    }
  }
}
