#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	hit_points = 100;
	energy_points = 50;
	attack_damage = 30;
	std::cout << "DiamondTrap " << name << " is born (default constructor) !" << std::endl;
}
DiamondTrap::DiamondTrap(std::string newName) : ClapTrap(newName +  "_clap_name"), FragTrap(newName +  "_clap_name"), ScavTrap(newName +  "_clap_name")
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
    std::cout << "I'm the DiamondTrap: \'" << name << "\', My ClapTrap name is: \'" << ClapTrap::name << "\'" << std::endl;
}
