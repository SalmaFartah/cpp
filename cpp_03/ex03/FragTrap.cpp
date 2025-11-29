#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
	std::cout << "FragTrap " << name << " is born (default constructor) !" << std::endl;
}

FragTrap::FragTrap(std::string newName) : ClapTrap(newName)
{
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
	std::cout << "FragTrap " << name << " is born (parametrized constructor) !" << std::endl;
	
}

FragTrap::FragTrap(const FragTrap& old) : ClapTrap(old)
{
	std::cout << "FragTrap " << name << " copied (copy constructor)" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& old)
{
	ClapTrap::operator=(old);
	std::cout << "FragTrap " << name << " assigned (copy assignment)" << std::endl;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " is now gone.." << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "Great job! Let's celebrate your success with a high five!" << std::endl;
}
