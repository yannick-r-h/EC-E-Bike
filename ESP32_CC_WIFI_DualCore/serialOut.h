#include "variables.h"

void serialOutput() {
  //serielle Ausgabe über USB von Messdaten
  Serial.print(4100); //Maximum für Plotter ausgeben
  Serial.printf(" Steuer_In: %4.2f \t", (double)analogRead(steuerInputPin));
  Serial.printf("Cur_1: %4.2f \t", current1); //Strom1 mit 4 Stellen vor und 2 Stellen nach dem Komma
  Serial.printf("Cur_2: %4.2f \t", current2);
  //Serial.printf("PulsAnalog: %4.f \t", pulsAnalog);
  Serial.printf("Puls_1: %4d \n", 4000 * puls1);
}
