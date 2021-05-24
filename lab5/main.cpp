//
// Created by Stefan on 5/19/2021.
//

#include "Number.h"
#include <iostream>

int main(){
    Number a("12FAE",16);
    a.print();
    a.switchBase();
    a.print();
}