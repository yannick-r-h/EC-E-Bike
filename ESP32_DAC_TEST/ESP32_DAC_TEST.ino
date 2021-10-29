int val = 0;

void setup() {
  pinMode(25, OUTPUT);
  pinMode(36, INPUT);
}

void loop() {
  dacWrite(25, val);
  val = (analogRead(36) / 16);
}
