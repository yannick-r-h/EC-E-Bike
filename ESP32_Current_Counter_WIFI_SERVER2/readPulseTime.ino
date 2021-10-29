void readPulseTime() {
  pulsintermediate = 0;
  for (int i = 0; i<= 100; i++) {
      pulsintermediate = (pulsintermediate + (analogRead(pulspin)));
  }
  pulsanalog = (pulsintermediate / 100);

  if (pulsanalog > 3500) {
    puls = 1;
  }
  else if (pulsanalog < 2600) {
    puls = 0;  
  }
}
