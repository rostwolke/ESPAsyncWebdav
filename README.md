# ESPAsyncWebdav
This project is a Webdav Plugin for ESPAsyncWebServer. So far it has only been testet with an ESP8266 but should 
also work for the ESP32.

## How to use
- Download the project archive and unpack it in your Arduino libraries folder
- Ensure that the folder name is ESPAsyncWebdav (remove the -master)
- Include the library in your project together with LittleFS
```
#include <LittleFS.h>
#include <AsyncWebdav.h>
```
- Initialize the plugin in a global variable (the paramter is the prefix path to access the webdav server)
```
AsyncWebdav dav("/dav");
```
- Initialize the file system in setup()
```
LittleFS.begin();
```
- Add the webdav handler to the webserver
```
server.addHandler(&dav);
```
That's it! To see the a full example, you can check the examples directory in the project.

## Access/Mount the ESP
To access the drive from Windows, open \\esp_hostname_or_ip\path_in_constructor\DavWWWRoot in the Windows Explorer, 
or use the Map Network Drive menu. The software works with NetDrive and WinSCP.
