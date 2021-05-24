//
// Created by Stefan on 5/19/2021.
//

#include "Coleg.h"

Coleg::Coleg(string &address, string &phone, string &firm) noexcept{
    this->phone = phone;
    this->address = address;
    this->firm = firm;
}
