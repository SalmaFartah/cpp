#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	health = 10;
	energy = 10;
	damage = 10;
}
ClapTrap::ClapTrap(const ClapTrap& old)
{
	this->name = old.name;
	this->health = old.health;
	this->energy = old.energy;
	this->damage = old.damage;
}

const ClapTrap& ClapTrap::operator=(const ClapTrap &old)
{
	this->name = old.name;
	this->health = old.health;
	this->energy = old.energy;
	this->damage = old.damage;
	return *this;
}

ClapTrap::ClapTrap(std::string newName)
{
	name = newName;
}

ClapTrap::~ClapTrap(){}

void ClapTrap::attack(const std::string& target)
{
	if (energy && health)
	{
		energy--;
		std::cout << "ClapTrap " << name << " attacks " << target << " , causing" << damage << " points of damage!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energy && health)
	{
		energy--;
		health += amount;
		std::cout << "ClapTrap " << name << " regains " << amount << " hit points !" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (energy && health)
	{
		health -= amount;
		std::cout << "ClapTrap " << name << " lose " << amount << " hit points !" << std::endl;
	}
}