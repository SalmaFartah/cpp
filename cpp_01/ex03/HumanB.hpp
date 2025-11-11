#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB
{
private:
	Weapon *myWeap;
	std::string name;

public:
	void	attack();
	void	setWeapon(Weapon& newWeap);
	HumanB(std::string newName);
	~HumanB(){};
};

#endif