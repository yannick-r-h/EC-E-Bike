#ifndef VARIABLES_H
#define VARIABLES_H

//WIFI-Setup

const char* ssid = "ESP32-Access-Point";      //WLAN Name
const char* password = "123456789";     //WLAN Passwort


//IO-Pins

const byte currentPin1 = 36;      //ADC0, für Shunt-Messung von 0-1000mV
const byte currentPin2 = 39;      //ADC3, für Shunt-Messung von 0-1000mV
const byte pulsPin = 34;          //ADC6, für Puls-Messung von 0-1000mV
const byte steuerInputPin = 35;   //ADC7, für Steuersignal Eingang von 0-1000mV

const byte loopTimingPin = 15;      //Debug-Timing Pin für den Haupt-Loop
const byte ledPin = 2;            //Debug Pin für bereinigten Magnetsensor


//Konfigurationsvariablen

const byte measurements = 20;     //Anzahl an Messungen pro Wert fuer Durschnitt

const double circumference = 2.13;      //circumference in meters

float shunt1 = 1;     //Widerstand von Shunt für Strom1
float shunt2 = 1;     //Widerstand von Shunt für Strom2

float cal1 = 1;     //Kalibrierungswert für Strom1
float cal2 = 1;     //Kalibrierungswert für Strom2


//Berechnungsvariablen

float current1 = 0;     //berechneter Strom aus Strommessung 1
float current2 = 0;     //berechneter Strom aus Strommessung 2
float current1intermediate = 0;     //Zwischenwert für Berechnung
float current2intermediate = 0;     //Zwischenwert für Berechnung

float pulsAnalog = 0;
float pulsIntermediate = 0;
bool puls = 0;      //Magnetsensor an oder aus
bool prePuls = 0;
unsigned long pulsStart = 1;
unsigned long pulsStop = 1;
unsigned long pulsTime[9];
float velocity = 0;       //speed in m/s


#endif
