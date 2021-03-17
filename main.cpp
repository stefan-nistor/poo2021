#include  <iostream>
#include "lab5/Number.h"
int main()

{
    Number n1("10110010",2);
    Number n2("734",8);
    Number n3("FF",16);

    Number n = n1;
    //n.switchBase(4);
    std::cout << n.number << '\n';
    n.print();
    n--;
    n.print();
    std::cout << n.number;

    return 0;

}
