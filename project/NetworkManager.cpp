#include "NetworkManager.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <regex>
#include <string>
#include<stdio.h>
#include <semaphore.h>
#include <cstring> 
#include <sys/mman.h>
#include <sys/stat.h>        
#include <fcntl.h>           
#include <unistd.h> 
#include <regex>
#include <thread>
#include <ctime>
#include <filesystem>

using namespace std;


//network manager


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



//producer functions and vars
void* ptr2;
int in=0;
sem_t* emp ;
sem_t* filled ;
sem_t* bsem ;

sem_t* bsem_his ;

int n=20;

#define SIZE_OF_PAGE 20*1024



void copystring_to_buffer(void*ptr, string temp,int index){

    strcpy(static_cast<char*>(ptr)+SIZE_OF_PAGE*index, temp.c_str());

    return;
}

void fetching_page(string url,int argc, char *argv[ ]){
    NetworkManager networkManager("cache");

        if (argc > 1) {
            url = argv[1];
        }

        

        string content = networkManager.fetchPage(url);
        if (content.empty()) {
            return ;
        }

        
        copystring_to_buffer(ptr2,content,in);
}

void make_file(string finalpath){
    
    ofstream outputFile(finalpath);
    outputFile<<"$";
    outputFile.close();


}


void producer_func(int argc, char *argv[ ],int tab_number, string dirpath){

    int i=-1;
    // bool back_flag=false;


    regex r("(http://localhost:8000/html_page_)[1-5](.html)");

    time_t now;
    tm* localTime;

    


    string tab_name="tab_"+to_string(tab_number)+".txt";
    string final_path=dirpath+"/"+tab_name;
    
    make_file(final_path);


    string prev;
    string next;

    vector<string>links;
    
    ifstream inputFile(final_path);

        inputFile>>next;
        
        inputFile.close();
    
    prev=next;

    links.push_back(prev);
    links.push_back(next);
    i+=2;
    

    while(1)
    {   
        

        ifstream inputFile(final_path);

        inputFile>>next;
        
        inputFile.close();

        if(next=="$exit")
        {
            remove(final_path.c_str());
            goto finish_func;
        }


        if(next==prev||!regex_match(next, r)){

            if(next!=prev)
                prev=next;
            
            // else if(next=="$back"&& !back_flag){
            //     if(i>=0&& regex_match(links[i], r)){
            //         next=links[i];
            //         i-=1;
            //         back_flag=true;
            //         goto linkopen;
            //     }
                    
            // }
            

            goto skip;

        }
        
        if(regex_match(next,r)){
            links.push_back(next);
            i=links.size();
        }

        // linkopen:
       
        prev=next;

        

        
        if(1){
        
        sem_wait(bsem_his);

        now = time(nullptr);
        localTime = localtime(&now);

        string history_path=dirpath+"/history.txt";

        ofstream outputFile(history_path, ios::app);
        outputFile << next;
        outputFile<<" ";
        outputFile<<asctime(localTime);
        outputFile<<"\n";
        outputFile.close();

        sem_post(bsem_his);

            
        }

        sem_wait(emp);
        sem_wait(bsem);

        fetching_page(next,argc,argv);

        

        in=(in+1)%n;


        sem_post(bsem);
        sem_post(filled);


        skip:

        ;

        // if(back_flag)
        // {
        //     next=back_flag;
        //     back_flag=false;
        // }


    }
    finish_func:
;
}



//python3 gen_html.py
// cd html_dataset
//python3 -m http.server

//g++  NetworkManager.h NetworkManager.cpp -lcurl  -o producer
//"http://localhost:8000/html_page_1.html"



int main(int argc, char *argv[ ]){
    
    string browser;
    cout<<"enter the name of the browser(without spaces): ";
    cin>>browser;
    string dirPath = "../"+browser; 
    filesystem::create_directories(dirPath);


    // cout<<"enter the size of the buffer: ";
    // cin>>n;


    //shared memory storing n
    const char* n_shared_name = "/size_of_buffer";
    //if previously it was used some where
    shm_unlink(n_shared_name);
    
    

    int shm_fd1 = shm_open(n_shared_name, O_CREAT | O_RDWR, 0666);  
    ftruncate(shm_fd1, sizeof(int));  
    void* ptr1 = mmap(0, sizeof(int), PROT_WRITE, MAP_SHARED, shm_fd1, 0);



    //shared memory storing strings
    const char* storing_web_pages = "/strings";
    shm_unlink(storing_web_pages);

    int shm_fd2 = shm_open(storing_web_pages, O_CREAT | O_RDWR, 0666);  

    //size of memory is 20*1024*40(each webpage can have atmost 20*1024 characters and we could have atmost 40 webpages)
    ftruncate(shm_fd2, SIZE_OF_PAGE*n*sizeof(char));  
    ptr2 = mmap(0, SIZE_OF_PAGE*n*sizeof(char), PROT_WRITE, MAP_SHARED, shm_fd2, 0);



    

    

    
    memcpy((int*)ptr1, &n, sizeof(int));
      

    

    

    //unlinking if we already have the semophore with same name
    sem_unlink("/emp");
    sem_unlink("/filled");
    sem_unlink("/bsem");

    //semophore for writing history to a file
    sem_unlink("/bsem_his");

    
    

    //semophores have to be declared before forking the consumer
    emp = sem_open("/emp", O_CREAT, 0644, n);
    filled = sem_open("/filled", O_CREAT, 0644, 0);
    bsem = sem_open("/bsem", O_CREAT, 0644, 1);

    bsem_his=sem_open("/bsem_his", O_CREAT, 0644, 1);

    pid_t pid1 =fork();  

    if (pid1 == 0) 
    {
        
        char *args[] = {nullptr};
        execvp("./consumer", args);  
        
        
    }

    vector<thread> threadVector;
    int number_of_tabs=0;
    while(1){
        cout<<"do you want to open one more tab ??--->Y/N: ";
        char opinion;
        cin>>opinion;
        if(opinion=='y'||opinion=='Y')
            threadVector.push_back(thread(producer_func,argc,argv, number_of_tabs++,dirPath));
        else
            goto joining_threads;
    }

    joining_threads:
    
    for (auto& temp : threadVector) {
        
            temp.join();
        
    }

    cout<<"all tabs have been closed!! ";


    //unmapping shared memory n
    munmap(ptr1, sizeof(int));
    close(shm_fd1);

    munmap(ptr2, SIZE_OF_PAGE*n*sizeof(char));
    close(shm_fd2);
    
    
}