void readCurrent1() {
  current1intermediate = 0;
  for (int i = 0; i<= 100; i++) {
      //current1intermediate = (current1intermediate + (A2D(analogRead(currentpin1)*1)*300.5393954819406));
      current1intermediate = (current1intermediate + (analogRead(currentpin1)));
  }
  current1 = (current1intermediate / (100 * cal1 * shunt1)); 
}

void readCurrent2() {
  current2intermediate = 0;
  for (int i = 0; i<= 100; i++) {
      //current2intermediate = (current2intermediate + (A2D(analogRead(currentpin2)*1)*300.5393954819406));
      current2intermediate = (current2intermediate + (analogRead(currentpin2)));
  }
  current2 = (current2intermediate / (100 * cal2 * shunt2)); 
}
