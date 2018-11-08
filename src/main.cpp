/**
 *Copyright (c) 2018 hisenzhang
 *
 *This software is released under the MIT License.
 *https://opensource.org/licenses/MIT
 */

#include <iostream>
#include <iomanip>

#include "../includes/parser.hpp"
#include "../includes/type.hpp"
#include "../includes/request.hpp"
#include "../includes/fileio.hpp"
#include "../includes/utils.hpp"

char DEBUG_FLAG = 0;

using namespace std;

int main(int argc, char** argv) {

    char* movie_id = (char*) malloc(sizeof(char)*16);
    *movie_id = 0;

    // check number of arguments
    for(size_t i = 1;i < argc;i++)
    {
        if (strcmp(argv[i],"--debug") == 0) DEBUG_FLAG = 1;
        if (strcmp(argv[i],"--id") == 0) movie_id = argv[i + 1];
    }
    if (!movie_id){
        err("ID not given.");
    }

    // parse config from config.json

    char* buffer = (char*) malloc(sizeof(char) * CONFIG_MAX_LENGTH);
    char* config_path = (char*) malloc(sizeof(char) * PATH_MAX_LENGTH);

    strcat(config_path,"config.json");
    readWholeFile(buffer,config_path);
    // if (!readWholeFile(buffer,config_path)) err("readWholeFile err");

    if (DEBUG_FLAG) cout << buffer << endl;

    // get api address and port, send request

    API_addr api_addr;
    parseCONFIG(&api_addr, buffer);

    free(buffer);
    free(config_path);

    buffer = NULL;
    config_path = NULL;

    CURLresponse response;
    curlRequest(&response, &api_addr, movie_id);

    // if request succeed, list them

    if (response.curlcode == CURLE_OK){
        info("HTTP OK");

        if (!response.response_string.empty()){
            // cout << response_string << endl;

            j_result movieList;
            parseJSON(&movieList, (char*) response.response_string.c_str());
            
            cout << std::left << setw(6) << "ID" << "TITLE" << endl << "----- -----" << endl;
            for (size_t i = 0; i < movieList.len; i++)
            {
                string str_i = to_string(i); // key is the string of given integer
                string title = movieList.content[str_i]["title"];
                // string img_link = movieList.content[str_i]["img_link"];
               
                size_t movie_id = movieList.content[str_i]["movie_id"];
                if (!(i % 10)) cout << endl;
                cout << std::left << setw(6) << movie_id << title << endl;
            }

            cout << "\n-----\nTotal " << movieList.len << endl;

            // free(response_char);
            // response_char = NULL;
        }
        else{
            err("Empty response from server.");
        }
    }
    else{
        cout << "HTTP Error. CURL error code " << response.curlcode << endl;
        
        return -1;
    }

    return 0;
}

// int main(int argc, char *argv[])
// {
//     CURL *curl;             //定义CURL类型的指针
//     CURLcode res;           //定义CURLcode类型的变量，保存返回状态码
//     curl = curl_easy_init();        //初始化一个CURL类型的指针
//     if(curl!=NULL)
//     {
//         curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
//         res = curl_easy_perform(curl);
//         curl_easy_cleanup(curl);
//     }
//     return 0;
// }
