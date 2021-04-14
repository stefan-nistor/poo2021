//
// Created by Stefan on 4/14/2021.
//

#include "lab8.h"
#include <string>
#include <map>
#include <queue>
#include <sstream>
#include <fstream>
#include <iostream>
#include <cstring>
#include <vector>
int lines_num;
int main(){

    std::ifstream fin ("../lab8/input.txt");
    std::string line;
    std::vector <std::string> text;

    while(std::getline (fin, line, '.')){
        text[lines_num++] = line;
    }

    for(auto i : text){

    }


    return 0;
}
