#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA
{
private:
	Weapon& WeaponA;
	std::string name;

public:
	HumanA(const char *newName, Weapon& newWeap);
	void attack();
	~HumanA();
};

#endif