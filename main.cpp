#include  <iostream>
#include "Sort.h"

int main() {

    Sort s1 ( 10, 5, 89);
    s1.print();

    Sort s2 ( {1, 5, 0 ,7, 23, 4, 2} );
    s2.insertSort();
    s2.print();

    Sort s3 ( new int[5] { 1, 7, 0, 4, 3 }, 5 );
    s3.print();

    Sort s4 ( 6, 7, 0, 4, 3, 9, 23);
    s4.bubbleSort();
    s4.print();

    Sort s5 ( "346,204,803,23,-9, 20" );
    s5.quickSort();
    s5.print();

    return 0;
}
