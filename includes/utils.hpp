/**
 *Copyright (c) 2018 hisenzhang
 *
 *This software is released under the MIT License.
 *https://opensource.org/licenses/MIT
 */

#ifndef _UTILS_H_
#define _UTILS_H_

#include "type.hpp"


void err(char* message, char* err_code);
void info(char* message);
void warn(char* message);
size_t writeFunction(void *ptr, size_t size, size_t nmemb, std::string* data);

#endif