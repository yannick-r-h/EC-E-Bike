// Import required libraries
#include "WiFi.h"
#include "ESPAsyncWebServer.h"


// Set your access point network credentials
const char* ssid = "ESP32-Access-Point";
const char* password = "123456789";

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

const int currentpin1 = 36; //ADC0, für Shunt-Messung von 0-1000mV
const int currentpin2 = 39; //ADC3, für Shunt-Messung von 0-1000mV
const int pulspin = 34; //ADC6, für Puls-Messung von 0-1000mV

float current1 = 0; //berechneter Strom aus Strommessung 1
float current2 = 0; //berechneter Strom aus Strommessung 2
float current1intermediate = 0;
float current2intermediate = 0;

float pulsanalog = 0;
float pulsintermediate = 0;
bool puls = 0 ;

long pulstime = 0;
long lastpulstime = 0;

float shunt1 = 1;
float shunt2 = 1;

float cal1 = 1;
float cal2 = 1;

long led = 0;





void setup() {
  pinMode(2, OUTPUT);
  pinMode(currentpin1, INPUT);
  pinMode(currentpin2, INPUT);
  pinMode(pulspin, INPUT);

  manualAdcSetup();

  Serial.begin(115200);
  // Serial port for debugging purposes
  Serial.println();
  
  serverSetup();
}

void loop() {
  /*if (led >= 100) {
    digitalWrite(2, !digitalRead(2));
    led = 0;
  }
  led = led + 1; */
  digitalWrite(2, puls);
  
  readCurrent1();
  readCurrent2();
  readPulseTime();
  //current1 = analogRead(currentpin1);
  
  serialOutput();
}
