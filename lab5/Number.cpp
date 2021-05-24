#include "Number.h"

/// returns an int from a char in base 10
int digitValue(char digit) noexcept{
    if(digit >= '0' && digit <= '9')
        return (int)digit - '0';

    return (int)digit - 'A' + 10;
}
/// returns a char from an int int base 10
char digitValue(int digit) noexcept{
    if (digit >=0 && digit <= 9)
        return (char)(digit + '0');

    return (char)(digit - 10 + 'A');
}

/// converts a number form base 10 in a given base (returns char*)
static char * fromDec (int value, int base) noexcept{
    int i = 0;
    char *result = new char[100];
    while(value){
        result[i++] = digitValue(value % base);
        value /= base;
    }
    result[i] = '\0';
    strrev(result);
    return result;
}

/// Number ctor from a char* and a base
Number::Number(const char *value, int base) noexcept(false){
    this->base = base;
    int length = strlen(value);
    digits = new char [length];
    strcpy(digits, value);

    ///save the number in base 10 for easier calculations
    for(int i = length - 1, power = 1; i >= 0; i--){
        if(digitValue(value[i]) >= base) {
            throw std::runtime_error("Invalid Number");
        }
        this->number += digitValue(value[i]) * power;
        power *= base;

    }
}
/// Number ctor from a value and a base
Number::Number(int value, int base) noexcept{
    this->base = base;
    this->number = value;
    this->digits = fromDec(value, base);
}

/// Copy ctor - usage: create a copy of an existing obj
Number::Number( Number const &other) noexcept{
    this->number = other.number;
    this->base = other.base;
    int len = strlen(other.digits);
    digits = new char[len + 1];
    std::memcpy ( digits, other.digits, len + 1 );
}
/// Move ctor - usage: allows moving an obj from lvalue to rvalue without creating a copy of it
Number::Number(Number &&other)  noexcept {
    /// shifts the resources without copying them
    number = other.number;
    base = other.base;

    char * temp = other.digits;
    other.digits = nullptr;
    this->digits = temp;
}

void Number::switchBase(int new_base) noexcept{
    base = new_base;
    digits = fromDec(number, base);
}

/// Overloading operator+ . The resulting Number obj has the greater base
Number operator+(const Number& a, const Number& b) noexcept{
    int base = a.getBase() > b.getBase() ? a.getBase() : b.getBase();
    return Number(fromDec(a.number + b.number,base), base );
}
/// Overloading operator- . The resulting Number obj has the greater base
Number operator-(const Number& a, const Number& b) noexcept{
    int base = a.getBase() > b.getBase() ? a.getBase() : b.getBase();
    return Number(fromDec(a > b ? a.number - b.number : b.number - a.number, base), base);
}

/// Prefix operator-- -> remove first digit ( most significant )
Number &Number::operator--() noexcept{

    strcpy(digits , digits + 1);

    this->convertToDecimal();
    return *this;
}

/// Postfix operator-- -> remove last digit ( least significant)
/// 'int' param does absolutely nothing. Just marks operator as postfix
Number& Number::operator--(int) noexcept{
    char * temp = digits;
    digits[getDigitsCount() - 1] = '\0';

    this->convertToDecimal();
    return *this;
}

/// Assignment operator between tho Number objs
Number& Number::operator= (const Number &obj) noexcept{
    if( this == &obj ) return *this;

    number = obj.number;
    base = obj.base;

    delete [] digits;
    digits = new char [getDigitsCount()];

    return *this;
}

void Number::convertToDecimal() noexcept{
    Number newNumber = Number(this->digits, this->base);
    this->number = newNumber.number;
}

Number &Number::operator+=(const Number &obj) noexcept{
    this->number += obj.number;
    this->convertToDecimal();
    return *this;
}

/// Overloading operator= to make things like "Number a = 10;" possible
Number &Number::operator=(const int value) noexcept{
    this->number = value;
    this->digits = fromDec(value, base);
    return *this;
}
/// Overloading operator= to make things like "Number a = "12FAE3";" possible
Number &Number::operator=(const char *value) noexcept{
    strcpy(digits, value);
    number = atoi(value);
    return *this;
}
