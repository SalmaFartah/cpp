#include "HumanA.hpp"


HumanA::HumanA(const char *newName, Weapon& newWeap) : WeaponA(newWeap)
{
    if (!newName)
        name = "";
    else
        name = newName;
}

HumanA::~HumanA(){}

void HumanA::attack()
{
    std::cout << name << " attacks with their " << WeaponA.getType() << std::endl;
}
