#include  <iostream>

float operator"" _Kelvin(const char *temperature){
    return float(strtod(temperature, nullptr)) - 273.0f;
}

float operator"" _Fahrenheit (const char* temperature){
    auto value = float(strtod(temperature, nullptr));
    return (value - 32) / 1.8f;

}

int main()
{
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;
    std::cout << a << ' ' << b;
    return 0;
}