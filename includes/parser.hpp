/**
 *Copyright (c) 2018 hisenzhang
 *
 *This software is released under the MIT License.
 *https://opensource.org/licenses/MIT
 */

#ifndef _PARSER_H_
#define _PARSER_H_

#include "type.hpp"


int parseJSON(j_result* buf, char* response);
int parseCONFIG(API_addr* buf, char* response);

#endif