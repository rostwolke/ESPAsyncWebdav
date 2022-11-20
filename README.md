# ESPAsyncWebdav
This project is a Webdav Plugin for ESPAsyncWebServer. Works with ESP8266 and ESP32.

## Important notice

To make this plugin work with ESPAsyncWebServer you currently (as of 2022-11-20) have to either patch me-no-dev's original code or use [my fork](https://github.com/rostwolke/ESPAsyncWebServer). To see which changes have to be done, see the [pull request](https://github.com/me-no-dev/ESPAsyncWebServer/pull/676).

## How to use
- Download the project archive and unpack it in your Arduino libraries folder
- Ensure that the folder name is ESPAsyncWebdav (remove the -master)
- Include the library in your project together with LittleFS
```
#include <LittleFS.h>
#include <AsyncWebdav.h>
```
- Initialize the plugin in a global variable (the parameter is the prefix path to access the webdav server)
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
