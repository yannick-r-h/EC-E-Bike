#ifndef VARIABLES_H
#define VARIABLES_H

//WIFI-Setup

const char* ssid = "ESP32-Access-Point";      //WLAN Name
const char* password = "123456789";     //WLAN Passwort


//IO-Pins
//Inputs
const byte currentPin1 = 36;        //ADC0, für Shunt-Messung von 0-1000mV
const byte currentPin2 = 39;        //ADC3, für Shunt-Messung von 0-1000mV
const byte pulsPin1 = 34;           //ADC6, für Puls-Messung von 0-1000mV
const byte pulsPin2 = 35;           //ADC7, für Puls-Messung von 0-1000mV
const byte steuerInputPin = 32;     //ADC4, für Steuersignal Eingang von 0-1000mV
const byte irgendeinPin = 33;       //ADC5, für irgendeinen Eingang von 0-1000mV
//Outputs
const byte steuerOutputPin1 = 25;   //DAC1, für Steuersignal von x-xxxxmV
const byte steuerOutputPin2 = 26;   //DAC2, für Steuersignal von x-xxxxmV
const byte loopTimingPin = 15;      //Debug-Timing Pin für den Haupt-Loop
const byte ledPin = 2;              //Debug Pin für bereinigten Magnetsensor



//Konfigurationsvariablen

const byte measurements = 20;     //Anzahl an Messungen pro Wert fuer Durschnitt

const double circumference = 2.13;      //circumference in meters

const double shunt1 = 1;     //Widerstand von Shunt für Strom1
const double shunt2 = 1;     //Widerstand von Shunt für Strom2

const double currentCal1 = 1;     //Kalibrierungswert für Strom1
const double currentCal2 = 1;     //Kalibrierungswert für Strom2


//Berechnungsvariablen

float current1 = 0;     //berechneter Strom aus Strommessung 1
float current2 = 0;     //berechneter Strom aus Strommessung 2

bool puls1 = 0;      //Magnetsensor1 an oder aus
bool puls2 = 0;      //Magnetsensor2 an oder aus

bool prePuls = 0;
unsigned long pulsStart = 1;
unsigned long pulsStop = 1;
unsigned long pulsTime[9];

float velocity = 0;       //speed in m/s, calculated from puls1


#endif
