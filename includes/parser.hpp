/**
 *Copyright (c) 2018 hisenzhang
 *
 *This software is released under the MIT License.
 *https://opensource.org/licenses/MIT
 */

#ifndef _PARSER_H_
#define _PARSER_H_

#include "type.hpp"

using namespace std;

j_result parseJSON(string response);
API_addr parseCONFIG(string response);

#endif