//
// Created by Stefan on 5/19/2021.
//

#ifndef LAB1_COLEG_H
#define LAB1_COLEG_H
#include "Contact.h"

class Coleg : public Contact{
private:
    string phone;
    string firm;
    string address;
public:

    Coleg() noexcept = default;
    Coleg(string& address, string& phone, string& firm) noexcept;

    [[nodiscard]] inline auto getPhone()    const noexcept -> string {return this-> phone;}
    [[nodiscard]] inline auto getFirm()     const noexcept -> string {return this-> firm;}
    [[nodiscard]] inline auto getAddress()  const noexcept -> string {return this-> address;}

};


#endif //LAB1_COLEG_H
