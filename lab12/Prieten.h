//
// Created by Stefan on 5/19/2021.
//

#ifndef LAB1_PRIETEN_H
#define LAB1_PRIETEN_H
#include "Contact.h"

class Prieten : public Contact{
private:

    string name;
    string birthday;
    string address;
    string phone;

public:

    Prieten() noexcept = default;
    Prieten(string &name, string& birthday, string& address, string& phone);

    [[nodiscard]] inline auto getName()     const noexcept -> string override {return this->name;}
    [[nodiscard]] inline auto getBirthday() const noexcept -> string  {return this->birthday;}
    [[nodiscard]] inline auto getAddress()  const noexcept -> string  {return this->address;}
    [[nodiscard]] inline auto getPhone()    const noexcept -> string  {return this->phone;}



};


#endif //LAB1_PRIETEN_H
