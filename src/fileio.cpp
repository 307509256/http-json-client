/**
 *Copyright (c) 2018 hisenzhang
 *
 *This software is released under the MIT License.
 *https://opensource.org/licenses/MIT
 */

#include "../includes/fileio.hpp"

using namespace std;

char* readWholeFile(string filename){

    char data[4096];
    ifstream config_json;
    if (!config_json){
        err("config.json not found.");
    }
//"/home/hisenzhang/C/http/config.json"
    config_json.open(filename,ios::in);
    int length;
    // config_json.open("file.txt");      // open input file
    config_json.seekg(0, std::ios::end);    // go to the end
    length = config_json.tellg();           // report location (this is the length)
    config_json.seekg(0, std::ios::beg);    // go back to the beginning
    auto buffer = new char[length];    // allocate memory for a buffer of appropriate dimension
    config_json.read(buffer, length);       // read the whole file into the buffer
    config_json.close();                    // close file handle

    // ... do stuff with buffer here ...

    return buffer;

}