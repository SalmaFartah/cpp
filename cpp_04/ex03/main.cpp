#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

// Assuming AMateria and derived classes (e.g., Ice, Cure) are defined
int main()
{
    std::string *hello = new std::string("hello");
    std::string *hello1 = hello;
    delete hello;
    std::cout << hello1->length() << std::endl;
    // AMateria *ice = new Ice;
    // std::cout << ice->getType() << std::endl;
    // Character simba("SIMBA");
    // simba.equip(ice);
    // delete ice;
    // std::cout << simba.slots[0]->getType() << std::endl;
    return 0;
}
