#include "HumanB.hpp"

HumanB::HumanB(const char *newName)
{
	WeaponB = NULL;
	if (!newName)
		name = "";
	else	
		name = newName;
}
HumanB::~HumanB(){}



void HumanB::attack()
{
	if (!WeaponB)
		std::cout << name << " can't attack without weapon !" << std::endl;
	else
    	std::cout << name << " attacks with their " << WeaponB->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& newWeap)
{
	WeaponB = &newWeap;
}
