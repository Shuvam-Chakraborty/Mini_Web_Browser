#include "NetworkManager.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <regex>

using namespace std;

NetworkManager::NetworkManager(const string& cacheDirPath) : cachePath(cacheDirPath) {
    filesystem::create_directories(cachePath);
    curl_global_init(CURL_GLOBAL_ALL);
}

NetworkManager::~NetworkManager() {
    curl_global_cleanup();
}

size_t NetworkManager::WriteCallback(void* contents, size_t size, size_t nmemb, string* userp) {
    userp->append((char*)contents, size * nmemb);
    return size * nmemb;
}

string NetworkManager::sanitizeUrl(const string& url) {
    regex invalid_chars("[^a-zA-Z0-9._-]");
    return regex_replace(url, invalid_chars, "_");
}

string NetworkManager::getCacheFilePath(const string& url) {
    return cachePath + "/" + sanitizeUrl(url) + ".cache";
}

bool NetworkManager::isCacheValid(const string& url) {
    auto cacheFile = getCacheFilePath(url);
    
    if (!filesystem::exists(cacheFile)) {
        return false;
    }

    auto lastModified = filesystem::last_write_time(cacheFile);
    auto now = filesystem::file_time_type::clock::now();
    auto duration = chrono::duration_cast<chrono::minutes>(now - lastModified);
    
    return duration < cacheExpiry;
}

void NetworkManager::saveToCache(const string& url, const string& content) {
    CacheEntry entry{
        content,
        chrono::system_clock::now()
    };
    memoryCache[url] = entry;

    ofstream cacheFile(getCacheFilePath(url), ios::binary);
    if (cacheFile.is_open()) {
        cacheFile.write(content.c_str(), content.size());
    }
}

string NetworkManager::loadFromCache(const string& url) {
    auto it = memoryCache.find(url);
    if (it != memoryCache.end()) {
        auto now = chrono::system_clock::now();
        auto duration = chrono::duration_cast<chrono::minutes>(now - it->second.timestamp);
        if (duration < cacheExpiry) {
            return it->second.content;
        }
        memoryCache.erase(it);
    }

    ifstream cacheFile(getCacheFilePath(url), ios::binary);
    if (cacheFile.is_open()) {
        stringstream buffer;
        buffer << cacheFile.rdbuf();
        return buffer.str();
    }
    
    return "";
}

string NetworkManager::fetchPage(const string& url) {
    if (isCacheValid(url)) {
        return loadFromCache(url);
    }

    CURL* curl = curl_easy_init();
    string readBuffer;
    
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 30L);
        
        CURLcode res = curl_easy_perform(curl);
        
        if (res != CURLE_OK) {
            cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;
        } else {
            saveToCache(url, readBuffer);
        }
        
        curl_easy_cleanup(curl);
    }
    
    return readBuffer;
}

void NetworkManager::clearCache() {
    memoryCache.clear();
    
    for (const auto& entry : filesystem::directory_iterator(cachePath)) {
        filesystem::remove(entry.path());
    }
}
