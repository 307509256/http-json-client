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

using namespace std;

int main(int argc, char** argv) {

    // check number of arguments

    if (argc!=2){
        err("ID not given.");
    }

    // parse config from config.json

    char* buffer = (char*) malloc(sizeof(char) * CONFIG_MAX_LENGTH);
    char* config_path = (char*) malloc(sizeof(char) * PATH_MAX_LENGTH);

    strcat(config_path,"config.json");
    readWholeFile(buffer,config_path);
    // if (!readWholeFile(buffer,config_path)) err("readWholeFile err");

    cout << buffer << endl;

    // get api address and port, send request

    API_addr api_addr;
    parseCONFIG(&api_addr, buffer);

    CURLresponse response;
    curlRequest(&response, &api_addr, argv[1]);

    // if request succeed, list them

    if (response.curlcode == CURLE_OK){
        info("HTTP OK");

        if (response.response_string.size() > 0){
            // cout << response_string << endl;
            
            char* response_char = (char*) malloc(sizeof(char*) * RES_MAX_LENGTH);
            strcpy(response_char,response.response_string.c_str());
            
            j_result movieList;
            parseJSON(&movieList, response_char);
            
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
        }
        else{
            err("Empty response from server.");
        }
    }
    else{
        cout << "HTTP Error. CURL error code " << response.curlcode << endl;
    }
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
