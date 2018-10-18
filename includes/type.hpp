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
#include "curl/curl.h"
#include "nlohmann/json.hpp"

using json = nlohmann::json;
using namespace std;

#define URL_MAX_LENGTH 4096
#define RES_MAX_LENGTH 4096 * 100
#define PATH_MAX_LENGTH 128
#define CONFIG_MAX_LENGTH 4096
#define URLENCODE_MAX_LENGTH 1024


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