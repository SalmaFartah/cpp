#ifndef DIMONDTRAP_HPP
#define DIMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
	std::string name;
public:
	
	DiamondTrap();
	DiamondTrap(const DiamondTrap& old);
	DiamondTrap& operator=(const DiamondTrap& old);
	~DiamondTrap();

	void whoAmI();
	DiamondTrap( std::string newName );
};

#endif
