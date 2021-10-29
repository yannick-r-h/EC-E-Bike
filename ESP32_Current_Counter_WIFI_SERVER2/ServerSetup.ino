void serverSetup() {
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

String readStrom1() {
  return String(current1);
}

String readStrom2() {
  return String(current2);
}

String readPuls() {
  return String(puls);
}
