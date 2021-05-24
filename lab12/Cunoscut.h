//
// Created by Stefan on 5/19/2021.
//

#ifndef LAB1_CUNOSCUT_H
#define LAB1_CUNOSCUT_H
#include "Contact.h"

class Cunoscut : public Contact {
private:
    string phone;
public:

    Cunoscut() noexcept = default;
    explicit Cunoscut(string& phone) noexcept;

    [[nodiscard]] inline auto getPhone() const noexcept -> string {return this->phone;}
};


#endif //LAB1_CUNOSCUT_H
