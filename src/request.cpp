/**
 *Copyright (c) 2018 hisenzhang
 *
 *This software is released under the MIT License.
 *https://opensource.org/licenses/MIT
 */

#include "../includes/request.hpp"

int escape(char* output, char* input){
    CURL *curl = curl_easy_init();
    if (curl){
        char *escaped = curl_easy_escape(curl, input, 0);
        if(escaped) {
            strcat(output,escaped);
            curl_free(escaped);

            return 0;
        }
    }

    return -1;
}

int curlRequest(CURLresponse* buf, API_addr* api_addr, char arg[ URLENCODE_MAX_LENGTH ]){

    CURL* curl = curl_easy_init();
    if (curl) {
        char* URL = (char*) malloc(sizeof(char*) * URL_MAX_LENGTH);
        char* urlencoded = (char*) malloc(sizeof(char*) * URLENCODE_MAX_LENGTH);
        
        escape(urlencoded,arg);

        // cout << URL << endl;
        strcat(URL,api_addr->scheme.c_str());
        strcat(URL,"://");
        strcat(URL,api_addr->ip_addr.c_str());
        strcat(URL,":");
        strcat(URL,api_addr->port.c_str());
        strcat(URL,api_addr->cmd.c_str());
        strcat(URL,api_addr->arg.c_str());
        strcat(URL,urlencoded);


        cout << URL << endl;
        curl_easy_setopt(curl, CURLOPT_URL, URL);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
        // // curl_easy_setopt(curl, CURLOPT_USERPWD, "user:pass");
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "curl/7.42.0");
        curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 50L);
        curl_easy_setopt(curl, CURLOPT_TCP_KEEPALIVE, 1L);
        
        // char* response_string = (char*) malloc(sizeof(char*) * 4096 * 100);;
        // char* header_string = (char*) malloc(sizeof(char*) * 4096);;
        string response_string;
        string header_string;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeFunction);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);
        curl_easy_setopt(curl, CURLOPT_HEADERDATA, &header_string);
         
        // char* url=NULL;
        long response_code;
        double elapsed;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &elapsed);
        // curl_easy_getinfo(curl, CURLINFO_EFFECTIVE_URL, &url);
        
        CURLcode res;
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        
       
        free(URL);
        free(urlencoded);

        curl = NULL;
        URL =  NULL;
        urlencoded = NULL;
        // url = NULL;

        buf->rescode = response_code;
        buf->elapsed = elapsed;
        buf->curlcode = res;
        buf->response_string = response_string;
        buf->header_string = header_string;
        // strcat(buf->response_string,response_string);
        // strcat(buf->header_string,header_string);
    
        return 0;
    }
    
    return -1;
}

