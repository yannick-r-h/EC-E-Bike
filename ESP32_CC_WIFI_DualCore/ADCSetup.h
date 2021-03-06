#include "variables.h"

void manualAdcSetup() {

  //ADC konfigurieren
  
  analogReadResolution(12);       //ADC Auflösung 12bit
  //analogSetCycles(8);
  //analogSetSamples(1);
  //analogSetClockDiv(1);
  //analogSetPinAttenuation(currentpin1, ADC_11db);
  //analogSetPinAttenuation(currentpin2, ADC_11db);
  //analogSetPinAttenuation(pulspin, ADC_0db);
  analogSetAttenuation(ADC_0db);  //ADC Eingangsbereich 0-1000mV

  //ADC-Eingaenge setzen
  adcAttachPin(voltagePin);
  adcAttachPin(currentPin1);
  adcAttachPin(currentPin2);
  adcAttachPin(bremsPin1);
  adcAttachPin(bremsPin2);
}
