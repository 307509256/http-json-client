/**
 *Copyright (c) 2018 hisenzhang
 *
 *This software is released under the MIT License.
 *https://opensource.org/licenses/MIT
 */

#include "../includes/utils.hpp"

using namespace std;

void err(char* message){
    cout << message << endl;
    exit(1);
}

void info(char* message){
    cout << message << endl;
}

void warn(char* message){
    cout << message << endl;
}

size_t writeFunction(void *ptr, size_t size, size_t nmemb, string* data) {
    data->append((char*) ptr, size * nmemb);
    return size * nmemb;
}