#include  <iostream>
#include "Math.h"

int main() {

    const char *a {"ana are memre"};
    const char *b {" si pere"};

    char * concat   = Math::Add(a, b);
    int sum         = Math::Add(4, 1, 2, 3, 4);

    std::cout << "1 + 2 + 3 + 4 =  " << sum << '\n';
    std::cout << concat;

    free(concat);
    return 0;
}
