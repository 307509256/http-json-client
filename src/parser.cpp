/**
 *Copyright (c) 2018 hisenzhang
 *
 *This software is released under the MIT License.
 *https://opensource.org/licenses/MIT
 */

#include "../includes/parser.hpp"

int parseJSON(j_result* buf, char* response){

    // cout << "pJSON" << endl;
    nlohmann::json j_string = nlohmann::json::parse(response);
    // cout << j_string << endl;
    
    buf->len = j_string["meta"]["length"];
    buf->content = j_string["content"];

    return 0;
}


int parseCONFIG(API_addr* buf, char* response){

    // cout << "pCONF" << endl;
    nlohmann::json j_string = nlohmann::json::parse(response);
    std::cout << j_string << std::endl;

    buf->ip_addr = j_string["ADDR"]["IP_ADDR"];
    buf->port = j_string["ADDR"]["PORT"];
    buf->scheme = j_string["ADDR"]["SCHEME"];
    buf->cmd = j_string["ADDR"]["CMD"];
    buf->arg = j_string["ADDR"]["ARG"];


    return 0;
}

