#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(const ScavTrap& old);
	void attack(const std::string& target);
	ScavTrap& operator=(const ScavTrap& old);
	ScavTrap(std::string newName);
	~ScavTrap();
	void guardGate();
};

#endif
