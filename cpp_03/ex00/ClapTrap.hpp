#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
private:
	std::string		name;
	unsigned int	health;
	unsigned int	energy;
	unsigned int	damage;
public:
	ClapTrap();
	ClapTrap(std::string newName);
	ClapTrap(const ClapTrap& old);
	const ClapTrap& operator=(const ClapTrap& old);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	~ClapTrap();
};

#endif