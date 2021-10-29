void manualAdcSetup() {
  analogReadResolution(12);
  analogSetWidth(12);
  analogSetCycles(8);  
  analogSetSamples(1);
  analogSetClockDiv(1);
  //analogSetPinAttenuation(currentpin1, ADC_11db);
  //analogSetPinAttenuation(currentpin2, ADC_11db);
  //analogSetPinAttenuation(pulspin, ADC_0db);
  analogSetAttenuation(ADC_0db);
  adcAttachPin(currentpin1);
  adcAttachPin(currentpin2);
  adcAttachPin(pulspin);
}
