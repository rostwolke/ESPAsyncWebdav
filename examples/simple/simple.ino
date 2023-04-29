#if defined(ESP32)
#include <WiFi.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#else
#error Platform not supported
#endif

#include <ESPAsyncWebServer.h>
#include <AsyncWebdav.h>

// LittleFS
#include <LittleFS.h>
#define FILESYSTEM LittleFS

// SPIFFS
// #include <SPIFFS.h>
// #define FILESYSTEM SPIFFS

// FFat
// #include <FFat.h>
// #define FILESYSTEM FFat

const char* ssid = "ssid";
const char* password = "pass";

AsyncWebServer server(80);

size_t totalBytes() { return FILESYSTEM.totalBytes(); }
size_t usedBytes() { return FILESYSTEM.usedBytes(); }

AsyncWebdav dav("/dav", FILESYSTEM, totalBytes, usedBytes);


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

  // init filesystem
  FILESYSTEM.begin();

  // add WebDAV handler
  server.addHandler(&dav);

  // start webserver
  server.serveStatic("/", FILESYSTEM, "/www/").setDefaultFile("index.html");
  server.begin();
}


void loop(void){
}
