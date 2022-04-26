#include "variables.h"

void serialOutput() {
  //serielle Ausgabe über USB von Messdaten
  Serial.print(4100); //Maximum für Plotter ausgeben
  Serial.printf("Cur_1: %4.2f \t", current1); //Strom1 mit 4 Stellen vor und 2 Stellen nach dem Komma
  Serial.printf("Cur_2: %4.2f \t", current2);
  //Serial.printf("PulsAnalog: %4.f \t", pulsAnalog);
  Serial.printf("Puls_1: %4d ", 4000 * puls1);
  Serial.printf("Velocity: %4.2f \t", velocity);
  Serial.printf("Puls_2: %4d ", 4000 * puls2);
  Serial.printf("Control_Velocity: %4.2f \n", controlVelocity);
}
