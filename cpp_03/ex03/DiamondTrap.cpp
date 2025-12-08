#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	hit_points = 100;
	energy_points = 50;
	attack_damage = 30;
	std::cout << "DiamondTrap " << name << " is born (parametrized constructor) !" << std::endl;
}
DiamondTrap::DiamondTrap(std::string newName) : ClapTrap(newName +  "_clap_name"), FragTrap(newName), ScavTrap(newName)
{
	name = newName;
	hit_points = 100;
	energy_points = 50;
	attack_damage = 30;
	std::cout << "DiamondTrap " << name << " is born (parametrized constructor) !" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& old): ClapTrap(old)
{
	name = old.name;
    std::cout << "DiamondTrap " << name << " copied (copy constructor)" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& old)
{
    ClapTrap::operator=(old);
	name = old.name;
    std::cout << "DiamondTrap " << name << " assigned (copy assignment)" << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << name << " is now gone.." << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "i'm the DiamondTrap: " << name << " my ClapTrap name is: " << ClapTrap::name << std::endl;
}
