//
// Created by rosawan on 04/03/2021.
//

#include "Math.h"
#include <stdarg.h>
#include <cstring>
#include <cstdlib>

int Math::Add(int a, int b) {
    return a + b;
}

int Math::Add(int a, int b, int c) {
    return a + b + c;
}

double Math::Add(double a , double b) {
    return a + b ;
}

double Math::Add(double a, double b, double c) {
    return a + b + c;
}

int Math::Mul(int a, int b) {
    return a*b;
}

int Math::Mul(int a, int b, int c) {
    return a * b * c;
}

double Math::Mul(double a, double b) {
    return a * b;
}

double Math::Mul(double a, double b, double c) {
    return a*b*c;
}

int Math::Add(int count, ...) {
    va_list elements;
    va_start(elements, count);

    int sum = 0;

    for(int i = 0; i < count; i++)
        sum += va_arg(elements,int);

    va_end(elements);

    return sum;
}

char *Math::Add(const char *a, const char *b) {
    if(!a || !b)
        return nullptr;

    int size_a = strlen(a);
    int size_b = strlen(b);

    char *c = (char*) std::malloc (size_a + size_b + 1);
    memcpy(c, a, size_a);
    memcpy(c + size_a, b, size_b);

    c[size_a + size_b] = '\0';
    return c;
}