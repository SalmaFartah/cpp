#include "HumanB.hpp"

HumanB::HumanB(std::string newName)
{
	name = newName;
}

void HumanB::attack()
{
    std::cout << name << " attacks with their " << (*myWeap).getType() << std::endl;
}

void HumanB::setWeapon(Weapon &newWeap)
{
	myWeap = &newWeap;
}
