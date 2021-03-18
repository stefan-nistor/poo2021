#ifndef LAB1_NUMBER_H
#define LAB1_NUMBER_H

#define GEN_COMP_OPERATOR(_opVal) \
    constexpr bool operator _opVal (Number const & other) const {return this->number _opVal other.number;}

#include <iostream>
#include <cstring>
#include <stdexcept>
class Number {
public:
    int number = 0;
    int base = 0;
    char *digits = {nullptr};

    void convertToDecimal();

public:

    Number                      (const char * value, int base = 10);
    Number                      (int  value, int base = 10);

    Number                      (Number const &obj) ;     ///copy ctor
    Number                      (Number &&obj) noexcept;  ///move ctor

    ~Number                     () {delete [] digits;}

    void switchBase             (int new_base);
    inline void print () const {std::cout << digits << '\n';}

    inline int getDigitsCount   () const {return strlen(digits);}
    constexpr inline int getBase() const {return this -> base;}

    friend Number operator+     (const Number& a, const Number& b);
    friend Number operator-     (const Number& a, const Number& b);

    constexpr inline char& operator[] (int index) const  { return this->digits[index];}

    Number& operator = (const Number& obj);
    Number& operator = (const int value);
    Number& operator = (const char* value);

    Number& operator += (const Number& obj);

    Number& operator --();    ///Prefix
    Number  operator --(int); ///Postfix


    GEN_COMP_OPERATOR (>)
    GEN_COMP_OPERATOR (<)
    GEN_COMP_OPERATOR (==)
    GEN_COMP_OPERATOR (!=)
    GEN_COMP_OPERATOR (>=)
    GEN_COMP_OPERATOR (<=)

};
#endif //LAB1_NUMBER_H*