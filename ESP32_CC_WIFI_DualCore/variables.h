#ifndef VARIABLES_H
#define VARIABLES_H

//WIFI-Setup

const char* ssid = "ESP32-Access-Point";      //WLAN Name
const char* password = "123456789";     //WLAN Passwort


//SD
File textFile;
String fileName = "Messwerte.txt";


//IO-Pins
//Inputs
const byte voltagePin = 27;         //ADC17, für Shunt-Messung von 0-1000mV
const byte steuerInputPin = 14;       //ADC16, für Steuersignal Eingang von 0-1000mV
const byte bremsPin1 = 12;           //ADC15, für Bremsen-Messung von 0-1000mV
const byte bremsPin2 = 13;           //ADC14, für Bremsen-Messung von 0-1000mV
const byte currentPin1 = 2;          //ADC12, für Shunt-Messung von 0-1000mV
const byte currentPin2 = 15;          //ADC13, für Shunt-Messung von 0-1000mV
const byte pedalPin = 17;             //digital
const byte pulsPin1 = 18;             //digital
const byte pulsPin2 = 19;             //digital

//Outputs
const byte steuerOutputPin1 = 25;   //DAC1, für Steuersignal von x-xxxxmV
const byte steuerOutputPin2 = 26;   //DAC2, für Steuersignal von x-xxxxmV
const byte debugTimingPin = 22;      //Debug-Timing Pin für den Control-Loop

//Duplex Pins
const byte VSPI_SCK = 18;
const byte VSPI_SS = 5;
const byte VSPI_MOSI = 23;
const byte VSPI_MISO = 19;


//Konfigurationsvariablen

const byte measurements = 10;       //Anzahl an Messungen pro Wert fuer Durschnitt
const int buffer_length = 255;      //Größe des Buffers fuer den gleitenden Durchschnitt

const float circumference = 2.13;   //circumference in meters

const float shunt1 = 1;             //Widerstand von Shunt für Strom1
const float shunt2 = 1;             //Widerstand von Shunt für Strom2

const float voltageCal = 1;
const float currentCal1 = 1;        //Kalibrierungswert für Strom1
const float currentCal2 = 1;        //Kalibrierungswert für Strom2


//Berechnungsvariablen

float voltage = 0;                  //berechnete Spannung aus Spannungsmessung

float current1 = 0;                 //berechneter Strom1 aus Strommessung
float current2 = 0;                 //berechneter Strom2 aus Strommessung

uint16_t volBuffer[buffer_length];  //Buffer fuer gleitenden Durchschnitt
uint16_t cur1Buffer[buffer_length];
uint16_t cur2Buffer[buffer_length];

byte volBuffer_i = 0;               //Index des aktuellsten Werts
byte cur1Buffer_i = 0;
byte cur2Buffer_i = 0;

bool puls1 = 0;      //Magnetsensor1 an oder aus
bool puls2 = 0;      //Magnetsensor2 an oder aus

bool prePuls = 0;
uint32_t pulsStart = 1;
uint32_t pulsStop = 1;
uint32_t pulsTime[9];

float velocity = 0;       //speed in m/s, calculated from puls1


#endif
