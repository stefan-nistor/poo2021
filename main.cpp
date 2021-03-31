#include  <iostream>
#include "lab7/Vector.hpp"
float operator"" _Kelvin(const char *temperature){
    return float(strtod(temperature, nullptr)) - 273.0f;
}

float operator"" _Fahrenheit (const char* temperature){
    auto value = float(strtod(temperature, nullptr));
    return (value - 32) / 1.8f;

}

Vector<int> v;

int main()
{

//    float a = 300_Kelvin;
//    float b = 120_Fahrenheit;
//    std::cout << a << ' ' << b;

    v.push(1);
    v.push(2);
    v.push(5);
    v.push(6);
    v.push(7);
    v.print();

    v.insert(23, 2);

//    v.print();
    return 0;

}