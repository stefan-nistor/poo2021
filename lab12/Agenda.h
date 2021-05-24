#ifndef LAB1_AGENDA_H
#define LAB1_AGENDA_H
#include "Contact.h"
#include "Prieten.h"
#include <list>
using namespace std;

class Agenda{
private:
    static list<Contact> contacts;
    list<int> values;
public:

    Agenda() noexcept = default;
    auto search(string&) const noexcept -> Contact&;
    auto friends()      const noexcept -> list<Prieten>;
    auto Delete()       const noexcept -> bool;
    auto add(Contact&)  const noexcept -> bool;

};


#endif //LAB1_AGENDA_H
