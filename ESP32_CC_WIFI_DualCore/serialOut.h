#include "variables.h"

void serialOutput() {
  //serielle Ausgabe über USB von Messdaten
  Serial.print(4100); //Maximum für Plotter ausgeben
  Serial.printf(" SteuerInput: %4.2f \t", (double)analogRead(steuerInputPin));
  Serial.printf("Current1: %4.2f \t", current1); //Strom1 mit 4 Stellen vor und 2 Stellen nach dem Komma
  Serial.printf("Current2: %4.2f \t", current2);
  Serial.printf("PulsAnalog: %4.f \t", pulsAnalog);
  Serial.printf("Puls: %4d \n", 4000 * puls);
}
