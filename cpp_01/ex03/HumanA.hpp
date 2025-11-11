#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA
{
private:
	Weapon& myWeap;
	std::string name;

public:
	void attack();
	HumanA(std::string newName, Weapon& newWeap);
	~HumanA(){};
};

#endif