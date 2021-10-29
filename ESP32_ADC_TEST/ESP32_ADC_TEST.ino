long adc_output = 0;
long adc_average = 0;
long adc_puls = 0;
float voltage = 0;


int voltagemeasure = 36;
int puls = 39;

void setup() {
  analogReadResolution(12);
  analogSetWidth(12);
  analogSetCycles(8);
  analogSetSamples(3);
  analogSetClockDiv(1);
  analogSetAttenuation(ADC_11db);
  adcAttachPin(36);
  adcAttachPin(39);
  pinMode(voltagemeasure, INPUT);
  pinMode(puls, INPUT);

  Serial.begin(115200);
  
}

void loop() {
  //adc_puls = analogRead(puls);
   for (int i = 0; i<= 100; i++) {
      adc_output = (adc_output + analogRead(36));
    }
  adc_average = (adc_output/100);
  adc_output = 0;
  //adc_output = analogRead(36);
  //voltage = (adc_output / 10);
  Serial.print("puls  ");
  Serial.print(adc_puls);
  Serial.print("  average  ");
  Serial.println(adc_average);
}
