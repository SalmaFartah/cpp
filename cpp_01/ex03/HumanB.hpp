#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB
{
private:
	Weapon *WeaponB;
	std::string name;

public:
	HumanB(const char *newName);
	void	attack();
	void	setWeapon(Weapon& newWeap);
	~HumanB();
};

#endif