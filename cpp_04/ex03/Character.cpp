#include "Character.hpp"


Character::Character()
{
	for (int i = 0; i < 4; i++)
		slots[i] = NULL;
}

Character::Character( Character& old )
{
	name = old.name;
	for (int i = 0; i < 4; i++)
	{
		if (slots[i]->getType() == "cure")
		{
			slots[i] = new Cure();
			*slots[i] = *old.slots[i];
		}
	}
}

Character::Character( std::string Name )
{
	for (int i = 0; i < 4; i++)
		slots[i] = NULL;
	name = Name;
}

Character& Character::operator=( Character& old )
{
	name = old.name;
	for (int i = 0; i < 4; i++)
	{
		if (slots[i] && slots[i]->getType() == "cure")
		{
			slots[i] = new Cure();
			*slots[i] = *old.slots[i];
		}
	}
	return *this;
}

std::string const & Character::getName() const
{
	return name;
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!slots[i] && m)
		{			
			slots[i] = m;
			break ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
		slots[idx] = NULL;
}
void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && slots[idx])
		slots[idx]->use(target);
}

Character::~Character(){}
