/**
 *Copyright (c) 2018 hisenzhang
 *
 *This software is released under the MIT License.
 *https://opensource.org/licenses/MIT
 */

#ifndef _UTILS_H_
#define _UTILS_H_

#include "type.hpp"

using namespace std;

void err(string message);
void info(string message);
void warn(string message);
size_t writeFunction(void *ptr, size_t size, size_t nmemb, string* data);

#endif