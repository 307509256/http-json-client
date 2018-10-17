/**
 *Copyright (c) 2018 hisenzhang
 *
 *This software is released under the MIT License.
 *https://opensource.org/licenses/MIT
 */

#ifndef _REQUEST_H_
#define _REQUEST_H_

#include "type.hpp"
#include "utils.hpp"

char* escape(char* input);
CURLresponse curlRequest(API_addr api_addr, char *arg);

#endif