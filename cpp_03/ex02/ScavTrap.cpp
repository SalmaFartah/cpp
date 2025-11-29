#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
	std::cout << "ScavTrap " << name << " is born (default constructor) !" << std::endl;
}

ScavTrap::ScavTrap(std::string newName) : ClapTrap(newName)
{
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
	std::cout << "ScavTrap " << name << " is born (parametrized constructor) !" << std::endl;
	
}

ScavTrap::ScavTrap(const ScavTrap& old) : ClapTrap(old)
{
	std::cout << "ScavTrap " << name << " copied (copy constructor)" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& old)
{
	ClapTrap::operator=(old);
	std::cout << "ScavTrap " << name << " assigned (copy assignment)" << std::endl;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " is now gone.." << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode" << std::endl;
}


void ScavTrap::attack(const std::string& target)
{
	if (energy_points && hit_points)
    {
        energy_points--;
        std::cout << "ScavTrap " << name << " attacks " << target << " , causing " << attack_damage << " points of damage!" << std::endl;
    }
    else if (!energy_points)
        std::cout << "ScavTrap " << name << " cannot attack, no energy left!" << std::endl;
    else
        std::cout << "ScavTrap" << name << " cannot attack, already dead!" << std::endl;
}
