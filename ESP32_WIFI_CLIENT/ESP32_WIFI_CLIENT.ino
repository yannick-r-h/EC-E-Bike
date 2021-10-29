/*
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/esp32-client-server-wi-fi/
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
*/

#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "ESP32-Access-Point";
const char* password = "123456789";

//Your IP address or domain name with URL path
const char* serverNameStrom1 = "http://192.168.4.1/strom1";
const char* serverNameStrom2 = "http://192.168.4.1/strom2";
const char* serverNamePuls = "http://192.168.4.1/puls";

#include <Wire.h>


float strom1;
float strom2;
float puls;

unsigned long previousMillis = 0;
const long interval = 100; 

void setup() {
  Serial.begin(115200);
  
  
  WiFi.begin(ssid, password);
  Serial.println("\n\nConnecting");
  while(WiFi.status() != WL_CONNECTED) { 
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  unsigned long currentMillis = millis();
  
  if(currentMillis - previousMillis >= interval) {
     // Check WiFi connection status
    if(WiFi.status()== WL_CONNECTED ){ 
      strom1 = httpGETRequest(serverNameStrom1).toFloat();
      strom2 = httpGETRequest(serverNameStrom2).toFloat();
      puls = httpGETRequest(serverNamePuls).toFloat();
      Serial.printf("Strom1: %4.2f\t\tStrom2: %4.2f\t\tPuls: %4.f\n", strom1, strom2, puls);
      

      // save the last HTTP GET Request
      previousMillis = currentMillis;
    }
    else {
      Serial.println("WiFi Disconnected");
    }
  }
}

String httpGETRequest(const char* serverName) {
  WiFiClient client;
  HTTPClient http;
    
  // Your Domain name with URL path or IP address with path
  http.begin(client, serverName);
  
  // Send HTTP POST request
  int httpResponseCode = http.GET();
  
  String payload = "--"; 
  
  if (httpResponseCode>0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    payload = http.getString();
  }
  else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  // Free resources
  http.end();

  return payload;
}
