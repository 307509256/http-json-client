/**
 *Copyright (c) 2018 hisenzhang
 *
 *This software is released under the MIT License.
 *https://opensource.org/licenses/MIT
 */

#include "../includes/parser.hpp"

int parseJSON(j_result* buf, char* response){

    // cout << "pJSON" << endl;
    nlohmann::json j_string = nlohmann::json::parse(response);
    // cout << j_string << endl;
    
    buf->len = j_string["meta"]["length"];
    buf->content = j_string["content"];

    return 0;
}


int parseCONFIG(API_addr* buf, char* response){

    // cout << "pCONF" << endl;
    nlohmann::json j_string = nlohmann::json::parse(response);
    
    extern char DEBUG_FLAG;
    if (DEBUG_FLAG) std::cout << j_string << std::endl;

    buf->ip_addr = j_string["ADDR"]["IP_ADDR"];
    buf->port = j_string["ADDR"]["PORT"];
    buf->scheme = j_string["ADDR"]["SCHEME"];
    buf->cmd = j_string["ADDR"]["CMD"];
    buf->arg = j_string["ADDR"]["ARG"];


    return 0;
}

int argParse(int argc, char** argv, char* movie_id){
        // check number of arguments
    extern char DEBUG_FLAG;
    for(int i = 1;i < argc;i++)
    {
        // std::cout <<  "index"<< i << std::endl;
        if ((strcmp(argv[i],"--debug") == 0) ||
            (strcmp(argv[i],"-d") == 0)) 
        {
            DEBUG_FLAG = 1;
        }

        else if ((strcmp(argv[i],"--random") == 0) ||
            (strcmp(argv[i],"-r") == 0))
        {
            strcpy(movie_id,"0");
        }

        else if ((strcmp(argv[i],"--id") == 0) ||
            (strcmp(argv[i],"-i") == 0))
        {   
            // movie_id = argv[i+1];
            if (++i < argc) {
                strcpy(movie_id,argv[i]);
                // std::cout << "id" << movie_id << '\n';
            }
            else {
                err("--id required but not specified.",NULL);
            }
        }

        else {
            err("Invalid arguments.",NULL);
        }
    }

    return 0;
}
