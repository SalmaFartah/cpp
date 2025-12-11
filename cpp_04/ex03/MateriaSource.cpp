#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		slots[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& old )
{
	for (int i = 0; i < 4; i++)
	{
		if (!old.slots[i])
			slots[i] = NULL;
		else
			slots[i] = old.slots[i]->clone();
	}
}

MateriaSource & MateriaSource::operator=(const MateriaSource& old)
{
	if (this == &old)
		return *this;
	for (int i = 0; i < 4; i++)
	{
		delete slots[i];
		if (!old.slots[i])
			slots[i] = NULL;
		else
			slots[i] = old.slots[i]->clone();
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!slots[i] && m)
		{
			slots[i] = m->clone();
			break ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (slots[i]->getType() == type)
			return slots[i]->clone();
	}
	return NULL;	
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		delete slots[i];
}