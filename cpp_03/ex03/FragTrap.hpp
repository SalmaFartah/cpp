#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap();
	FragTrap(const FragTrap& old);
	FragTrap& operator=(const FragTrap& old);
	FragTrap(std::string newName);
	void highFivesGuys(void);
	~FragTrap();
};

#endif