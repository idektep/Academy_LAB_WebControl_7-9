#include <Arduino.h>
#ifdef ESP32
#include <WiFi.h>
#include <AsyncTCP.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#endif
#include <ESPAsyncWebSrv.h>

//-----------------------------------------------Set your device name and password.--------------------------------------//
const char *ssid = "Test Dashboard";
const char *password = "12345678";
//-----------------------------------------------------------------------------------------------------------------------//

//-------------------------------------------------edit Parameter-------------------------------------------------------//

//--------------------------------------Define AGV------------------------------------------//
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define UP_LEFT 5
#define UP_RIGHT 6
#define DOWN_LEFT 7
#define DOWN_RIGHT 8
#define TURN_LEFT 9
#define TURN_RIGHT 10
#define STOP 0

AsyncWebServer server(80);
AsyncWebSocket ws("/ws");

void setup(void) {
  Serial.begin(115200);
  motorsetup();
  
  initWiFi();
  Serial.print("RRSI: ");
  Serial.println(WiFi.RSSI());
  server.on("/", HTTP_GET, handleRoot);
  server.onNotFound(handleNotFound);
  ws.onEvent(onWebSocketEvent);
  server.addHandler(&ws);
  server.begin();
  Serial.println("HTTP server started");

}
void loop() {
  ws.cleanupClients();
}
