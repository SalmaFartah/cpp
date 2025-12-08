#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(const ScavTrap& old);
	ScavTrap& operator=(const ScavTrap& old);
	ScavTrap(std::string newName);
	~ScavTrap();

	void attack(const std::string& target);
	void guardGate();
};

#endif
