//
// Created by Stefan on 5/19/2021.
//

#ifndef LAB1_CONTACT_H
#define LAB1_CONTACT_H


#include <string>
using namespace std;
class Contact {
private:

    string name;
//    string birthday;
//    string address;
//    string phone;
//    string firm;


      [[nodiscard]] virtual auto getName()        const noexcept -> string = 0;
//    [[nodiscard]] virtual auto getPhone()       const noexcept -> string = 0;
//    [[nodiscard]] virtual auto getBirthday()    const noexcept -> string = 0;
//    [[nodiscard]] virtual auto getAddress()     const noexcept -> string = 0;
//    [[nodiscard]] virtual auto getFirm()        const noexcept -> string = 0;

public:
    Contact() noexcept = default;
};


#endif //LAB1_CONTACT_H
