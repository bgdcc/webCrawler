// #include <bits/stdc++.h>
#include <unordered_map>
#include <curl/curl.h>
#include <stdio.h>
#include <regex>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

mutex m;

void getPage(const char* url, const char* fileName) {
    CURL* easyHandle = curl_easy_init();
    
    curl_easy_setopt(easyHandle, CURLOPT_URL, url);
    FILE* file = fopen(fileName, "w");

    curl_easy_setopt(easyHandle, CURLOPT_URL, file);
    curl_easy_perform(easyHandle);
    curl_easy_cleanup(easyHandle);
    fclose(file);
}