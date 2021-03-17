#include "Number.h"

int digitValue(char digit) {
    if(digit >= '0' && digit <= '9')
        return (int)digit - '0';

    return (int)digit - 'A' + 10;
}

char digitValue(int digit) {
    if (digit >=0 && digit <= 9)
        return (char)(digit + '0');

    return (char)(digit - 10 + 'A');
}

Number::Number(const char *value, int base) {
    this->base = base;
    int length = strlen(value);
    digits = new char [length];
    strcpy(digits, value);


    for(int i = length - 1, power = 1; i >= 0; i--){
        if(digitValue(value[i]) >= base){
            std::cout << value[i] << '\n';
            throw std::runtime_error ("Invalid Number");
        }
        this->number += digitValue(value[i]) * power;
        power *= base;
    }
}

Number::Number( Number const &other) {
    this->number = other.number;
    this->base = other.base;
    digits = other.digits;

//    this->digits = new char [other.getDigitsCount()];
//    strcpy(this->digits, other.digits);
}

Number::Number(Number &&other)  noexcept {
    number = other.number;
    base = other.base;

    char * temp = other.digits;
    other.digits = nullptr;
    this->digits = temp;
}

static char * fromDec (int value, int base){
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

void Number::switchBase(int new_base) {
    base = new_base;
    digits = fromDec(number, base);
}

Number operator+(const Number& a, const Number& b) {
    int base = a.getBase() > b.getBase() ? a.getBase() : b.getBase();
    return Number(fromDec(a.number + b.number,base), base );
}

Number operator-(const Number& a, const Number& b) {
    int base = a.getBase() > b.getBase() ? a.getBase() : b.getBase();

    return Number(fromDec(a > b ? a.number - b.number : b.number - a.number, base), base);
}



//TODO: Check functionality of overloading operator--
/// Prefix -> remove first digit ( most significant )
Number &Number::operator--() {

    /// remove first digit ( left-most ) : shift *digits with 1 position to the left
    strcpy(digits , digits + 1);

    /// Convert new char representation to decimal value

    for(int i = getDigitsCount() - 1, power = 1; i >= 0; i--){
        if(digitValue(digits[i]) >= base){
            std::cout << digits[i] << '\n';
            throw std::runtime_error ("Invalid Number");
        }
        this->number += digitValue(digits[i]) * power;
        power *= base;
    }
    return *this;
}
/// Postfixx -> remove last digit ( least significant)
Number Number::operator--(int index) {

    /// Remove last digit ( right - most ) : shift *digits with 1 position to the right

    char * temp = digits;

    digits[getDigitsCount() - 1] = '\0';

    /// Convert new char representation to decimal value
    //TODO: make a method with this (convertToDecimal(const char * value);)



    return *this;
}


Number& Number::operator= (const Number &obj) {

    if( this == &obj ) return *this;

    delete [] digits;
    number = obj.number;
    base = obj.base;
    digits = new char [getDigitsCount()];
    return *this;

}
