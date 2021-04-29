#include "Array.h"
#include <iostream>
int main(){
    Array<int> a(5);
    Array<int> b(2);
    try{
        printf("%d",a[7]);
        a.Delete(6);
    }
    catch(IndexException& e){
        printf("Caught exception: %s\n", e.what());
    }

}