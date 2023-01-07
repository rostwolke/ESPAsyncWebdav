#include <Arduino.h>
#include <FS.h>


enum DavResourceType { DAV_RESOURCE_NONE, DAV_RESOURCE_FILE, DAV_RESOURCE_DIR };
enum DavDepthType { DAV_DEPTH_NONE, DAV_DEPTH_CHILD, DAV_DEPTH_ALL };


class AsyncWebdav: public AsyncWebHandler {
    public:
        AsyncWebdav(const String& url, fs::FS &fs);

        virtual bool canHandle(AsyncWebServerRequest *request) override final;
        virtual void handleRequest(AsyncWebServerRequest *request) override final;
        virtual void handleBody(AsyncWebServerRequest *request, unsigned char *data, size_t len, size_t index, size_t total) override final;
        const char* url() const {
            return _url.c_str();
        }

    private:
        String _url;
        fs::FS _fs;
        void handlePropfind(const String& path, DavResourceType resource, AsyncWebServerRequest * request);
        void handleGet(const String& path, DavResourceType resource, AsyncWebServerRequest * request);
        void handlePut(const String& path, DavResourceType resource, AsyncWebServerRequest * request, unsigned char *data, size_t len, size_t index, size_t total);
        void handleLock(const String& path, DavResourceType resource, AsyncWebServerRequest * request);
        void handleUnlock(const String& path, DavResourceType resource, AsyncWebServerRequest * request);
        void handleMkcol(const String& path, DavResourceType resource, AsyncWebServerRequest * request);
        void handleMove(const String& path, DavResourceType resource, AsyncWebServerRequest * request);
        void handleDelete(const String& path, DavResourceType resource, AsyncWebServerRequest * request);
        void handleHead(DavResourceType resource, AsyncWebServerRequest * request);
        void handleNotFound(AsyncWebServerRequest * request);
        void sendPropResponse(AsyncResponseStream *response, boolean recursing, File *curFile);
        String urlToUri(String url);

};