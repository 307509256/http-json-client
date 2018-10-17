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

int escape(char* output, char* input);
int curlRequest(CURLresponse* buf, API_addr* api_addr, char arg[1024]);

#endif