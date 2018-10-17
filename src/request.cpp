/**
 *Copyright (c) 2018 hisenzhang
 *
 *This software is released under the MIT License.
 *https://opensource.org/licenses/MIT
 */

#include "../includes/request.hpp"

char* escape(char* input){
    CURL *curl = curl_easy_init();
    if (curl){
        char *output = curl_easy_escape(curl, input, 0);
        if(output) {
            char *buffer;
            buffer = output;
            curl_free(output);

            return buffer;
        }
    }
}

CURLresponse curlRequest(API_addr api_addr, char arg[1024]){
    CURLresponse buffer;
    auto curl = curl_easy_init();
    if (curl) {
        char URL[4096];
        // cout << URL << endl;
        strcat(URL,api_addr.scheme.c_str());
        strcat(URL,"://");
        strcat(URL,api_addr.ip_addr.c_str());
        strcat(URL,":");
        strcat(URL,api_addr.port.c_str());
        strcat(URL,api_addr.cmd.c_str());
        strcat(URL,api_addr.arg.c_str());
        strcat(URL,escape(arg));


        cout << URL << endl;
        curl_easy_setopt(curl, CURLOPT_URL, URL);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
        // // curl_easy_setopt(curl, CURLOPT_USERPWD, "user:pass");
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "curl/7.42.0");
        curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 50L);
        curl_easy_setopt(curl, CURLOPT_TCP_KEEPALIVE, 1L);
        
        string response_string;
        string header_string;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeFunction);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);
        curl_easy_setopt(curl, CURLOPT_HEADERDATA, &header_string);
        
        char* url=NULL;
        long response_code;
        CURLcode res;
        double elapsed;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &elapsed);
        curl_easy_getinfo(curl, CURLINFO_EFFECTIVE_URL, &url);
        
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        curl = NULL;
        url = NULL;

        buffer.rescode = response_code;
        buffer.response_string = response_string;
        buffer.elapsed = elapsed;
        buffer.header_string = header_string;
        buffer.curlcode = res;

        return buffer;
    }
}

