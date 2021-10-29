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

String readStrom1() {
  return String(current1);
}

String readStrom2() {
  return String(current2);
}

String readPuls() {
  return String(puls);
}

void setup() {
  pinMode(2, OUTPUT);
  pinMode(currentpin1, INPUT);
  pinMode(currentpin2, INPUT);
  pinMode(pulspin, INPUT);

  manualAdcSetup();

  Serial.begin(115200);
  // Serial port for debugging purposes
  Serial.println();
  
  // Setting the ESP as an access point
  Serial.print("Setting AP (Access Point)…");
  // Remove the password parameter, if you want the AP (Access Point) to be open
  WiFi.softAP(ssid, password);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);

  server.on("/strom1", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readStrom1().c_str());
  });
  server.on("/strom2", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readStrom2().c_str());
  });
  server.on("/puls", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readPuls().c_str());
  });
  
  // Start server
  server.begin();
}

void loop() {
  //if (led >= 100) {
    //digitalWrite(2, !digitalRead(2));
    //led = 0;
 // }
 // led = led + 1;
  digitalWrite(2, puls);
  
  readCurrent1();
  readCurrent2();
  readPulseTime();
  //current1 = analogRead(currentpin1);
  
  Serial.print("Current1  ");
  Serial.print(current1);
  Serial.print("  Current2  ");
  Serial.print(current2);
  Serial.print("  PulsAnalog  ");
  Serial.print(pulsanalog);
  Serial.print("  Puls  ");
  Serial.println(puls);
}




void manualAdcSetup() {
  analogReadResolution(12);
  analogSetWidth(12);
  analogSetCycles(8);  
  analogSetSamples(1);
  analogSetClockDiv(1);
  //analogSetPinAttenuation(currentpin1, ADC_11db);
  //analogSetPinAttenuation(currentpin2, ADC_11db);
  //analogSetPinAttenuation(pulspin, ADC_0db);
  analogSetAttenuation(ADC_0db);
  adcAttachPin(currentpin1);
  adcAttachPin(currentpin2);
  adcAttachPin(pulspin);
}

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

float A2D(float SenVal)
{
if(SenVal<1) return(0);
//else if (SenVal>4094) return(99);
else return(-0.000000000023926 * pow(SenVal,3) + 0.000000094746 * pow(SenVal,2) + 0.00074539 * SenVal + 0.14925);
}

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
