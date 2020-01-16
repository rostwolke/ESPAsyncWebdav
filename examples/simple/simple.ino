#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <LittleFS.h>
#include <AsyncWebdav.h>

const char* ssid = "ssid";
const char* password = "pass";

AsyncWebServer server(80);
AsyncWebdav dav("/dav");


void setup(void){
  // init serial and wifi
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("");

  // wait for connection
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // init spiffs
  LittleFS.begin();

  // add websocket handler
  server.addHandler(&dav);

  // start webserver
  server.serveStatic("/", LittleFS, "/").setDefaultFile("index.html");
  server.begin();
}


void loop(void){
}
