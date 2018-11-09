/**
 *Copyright (c) 2018 hisenzhang
 *
 *This software is released under the MIT License.
 *https://opensource.org/licenses/MIT
 */

#include "../includes/utils.hpp"

using namespace std;

// Color Code
// Background 40--49               Foreground 30--39
//            40: Black                       30: Black
//            41: Red                         31: Red
//            42: Green                       32: Green
//            43: Yellow                      33: Yellow
//            44: Blue                        34: Blue
//            45: Purple                      35: Purple
//            46: Dark Green                  36: Dark Green
//            47: White                       37: White

void err(char* message, char* err_code){
    if (err_code)
        cout << "\033[41;30m[ERR]\033[0m " << message << err_code << endl;
    else
        cout << "\033[41;30m[ERR]\033[0m " << message << endl;
    exit(1);
}

void info(char* message){
    extern char DEBUG_FLAG;
    if (DEBUG_FLAG) cout << "\033[42;30m[INFO]\033[0m " << message << endl;
}

void warn(char* message){
    extern char DEBUG_FLAG;
    if (DEBUG_FLAG) cout << "\033[43;30m[WARN]\033[0m " << message << endl;
}

size_t writeFunction(void *ptr, size_t size, size_t nmemb, string* data) {
    data->append((char*) ptr, size * nmemb);
    return size * nmemb;
}