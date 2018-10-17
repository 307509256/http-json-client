/**
 *Copyright (c) 2018 hisenzhang
 *
 *This software is released under the MIT License.
 *https://opensource.org/licenses/MIT
 */

#include "../includes/parser.hpp"

j_result parseJSON(string response){

    // cout << "pJSON" << endl;
    json j_string = json::parse(response);
    // cout << j_string << endl;
    j_result buf;
    buf.len = j_string["meta"]["length"];
    buf.content = j_string["content"];

    return buf;

}


API_addr parseCONFIG(string response){

    // cout << "pCONF" << endl;
    json j_string = json::parse(response);
    cout << j_string << endl;
    API_addr buf;
    buf.ip_addr = j_string["ADDR"]["IP_ADDR"];
    buf.port = j_string["ADDR"]["PORT"];
    buf.scheme = j_string["ADDR"]["SCHEME"];
    buf.cmd = j_string["ADDR"]["CMD"];
    buf.arg = j_string["ADDR"]["ARG"];


    return buf;
}

