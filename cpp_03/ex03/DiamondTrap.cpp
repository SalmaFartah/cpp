#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
    
}
DiamondTrap::DiamondTrap(std::string newName) : ClapTrap(newName +  "_clap_name"), ScavTrap(newName +  "_clap_name"), FragTrap(newName +  "_clap_name")
{
	name = newName;
	hit_points = FragTrap::hit_points;
	energy_points = ScavTrap::energy_points;
	attack_damage = FragTrap::attack_damage;
	std::cout << "DiamondTrap " << name << " is born (parametrized constructor) !" << std::endl;
}

DiamondTrap::DiamondTrap(const FragTrap& old): ClapTrap(old)
{
    std::cout << "DiamondTrap " << name << " copied (copy constructor)" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const FragTrap& old)
{
    ClapTrap::operator=(old);
    std::cout << "DiamondTrap " << name << " assigned (copy assignment)" << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << name << " is now gone.." << std::endl;
}


void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap " << name << " has ClapTrap name " << ClapTrap::name << std::endl;
}
