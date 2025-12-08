#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap();
	FragTrap(const FragTrap& old);
	FragTrap& operator=(const FragTrap& old);
	FragTrap(std::string newName);
	~FragTrap();

	void highFivesGuys(void);
};

#endif