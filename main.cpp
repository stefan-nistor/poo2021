#include  <iostream>
#include "Masina.h"

int main()
{
    Masina m;
    m.vopseste("culoare bostan");

    std::cout << m.getMarca() << ' ' << m.getCuloare();
    return 0;
}
