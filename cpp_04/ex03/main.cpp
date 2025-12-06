#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int main()
{
    AMateria *ice = new Ice;
    std::cout << ice->getType() << std::endl;
    Character simba("SIMBA");
    simba.equip(NULL);
    delete ice;
    simba.use(0, simba);
    return 0;
}
