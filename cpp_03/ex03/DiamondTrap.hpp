#ifndef DIMONDTRAP_HPP
#define DIMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string name;
public:
	
	DiamondTrap();
	DiamondTrap(const FragTrap& old);
	DiamondTrap& operator=(const FragTrap& old);
	~DiamondTrap();

	void whoAmI();
	DiamondTrap( std::string newName );
};

#endif