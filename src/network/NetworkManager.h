#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <string>
#include <unordered_map>
#include <filesystem>
#include <chrono>
#include <curl/curl.h>

using namespace std;

class NetworkManager {
private:
    struct CacheEntry {
        string content;
        chrono::system_clock::time_point timestamp;
    };

    string cachePath;
    unordered_map<string, CacheEntry> memoryCache;
    const chrono::minutes cacheExpiry{30};

    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, string* userp);
    string getCacheFilePath(const string& url);
    bool isCacheValid(const string& url);
    void saveToCache(const string& url, const string& content);
    string loadFromCache(const string& url);
    string sanitizeUrl(const string& url);

public:
    NetworkManager(const string& cacheDirPath = "cache");
    ~NetworkManager();

    string fetchPage(const string& url);
    void clearCache();
};

#endif // NETWORKMANAGER_H
