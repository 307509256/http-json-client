/**
 *Copyright (c) 2018 hisenzhang
 *
 *This software is released under the MIT License.
 *https://opensource.org/licenses/MIT
 */

#ifndef _TYPE_H_
#define _TYPE_H_

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

struct API_addr{
    string ip_addr;
    string port;
    string scheme;
    string cmd;
    string arg;
};

struct j_result{
    size_t len;
    json content;
};

struct CURLresponse{
    string response_string;
    string header_string;
    long rescode;
    double elapsed;
    CURLcode curlcode;
};

#endif