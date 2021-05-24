#ifndef LAB1_NUMBER_H
#define LAB1_NUMBER_H

#define GEN_COMP_OPERATOR(_opVal) \
    constexpr bool operator _opVal (Number const & other) const {return this->number _opVal other.number;}

#include <iostream>
#include <cstring>
#include <stdexcept>
class Number {
private:
    int number = 0;
    int base = 0;
    char *digits = {nullptr};

    void convertToDecimal() noexcept;

public:

    explicit Number                      (const char * value, int base = 10) noexcept(false);
    explicit Number                      (int  value, int base = 10) noexcept;

    Number                      (Number const &obj) noexcept;     ///copy ctor
    Number                      (Number &&obj) noexcept;  ///move ctor

    ~Number                     () {delete [] digits;}

    void switchBase             (int new_base) noexcept;

    inline void print () const noexcept {std::cout << digits << '\n';}

    inline int getDigitsCount   () const noexcept {return strlen(digits);}
    constexpr inline int getBase() const noexcept {return this -> base;}


    /// being friend methods, we do not have access to "this"
    friend Number operator+     (const Number& a, const Number& b) noexcept;
    friend Number operator-     (const Number& a, const Number& b) noexcept;

    constexpr inline char& operator[] (int index) const noexcept(false) { return this->digits[index];}

    Number& operator = (const Number& obj) noexcept;
    Number& operator = (const int value)   noexcept;
    Number& operator = (const char* value) noexcept;

    Number& operator += (const Number& obj) noexcept;

    Number& operator --() noexcept;    ///Prefix
    Number&  operator --(int) noexcept; ///Postfix


    GEN_COMP_OPERATOR (>)
    GEN_COMP_OPERATOR (<)
    GEN_COMP_OPERATOR (==)
    GEN_COMP_OPERATOR (!=)
    GEN_COMP_OPERATOR (>=)
    GEN_COMP_OPERATOR (<=)

};
#endif //LAB1_NUMBER_H*