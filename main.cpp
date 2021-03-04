#include  <iostream>
#include "Canvas.h"
Canvas c(32,32);
int main() {
    c.DrawCircle(16,16,10,'#');
    c.FillCircle(16,16,10,'$');
    c.Print();
    c.Clear();
    c.DrawRect(10,10, 28, 28, 'a');
    c.FillRect(10,10,28,28, 'b');
    c.Print();

    return 0;
}
