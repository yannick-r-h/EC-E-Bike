#include "variables.h"

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);


String readVoltage() {
  return String(voltage);
}

String readVelocity() {
  return String(velocity);
}

String readStrom1() {
  return String(current1);
}

String readStrom2() {
  return String(current2);
}

String readPuls1() {
  return String(puls1);
}

String readPuls2() {
  return String(puls2);
}

void serverSetup( void * parameter ) {
  delay(10);
  Serial.printf("Webserver running on Core %d\n ", xPortGetCoreID());
  // Setting the ESP as an access point
  Serial.println("Setting AP (Access Point)…");
  // Remove the password parameter, if you want the AP (Access Point) to be open
  WiFi.softAP(ssid, password);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);

  server.on("/spannung", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send_P(200, "text/plain", readVoltage().c_str());
  });
  server.on("/geschwindigkeit", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send_P(200, "text/plain", readVelocity().c_str());
  });
  server.on("/strom1", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send_P(200, "text/plain", readStrom1().c_str());
  });
  server.on("/strom2", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send_P(200, "text/plain", readStrom2().c_str());
  });
  server.on("/puls1", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send_P(200, "text/plain", readPuls1().c_str());
  });
  server.on("/puls2", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send_P(200, "text/plain", readPuls2().c_str());
  });

  // Start server
  server.begin();
  delay(100);
  Serial.println();
  Serial.println("---------------------------------------------");
  Serial.println();
  delay(500);
  vTaskDelete( NULL );
}
