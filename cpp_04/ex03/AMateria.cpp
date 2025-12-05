#include "AMateria.hpp"

AMateria::AMateria(){}

AMateria::AMateria(std::string const & type)
{
	this->type = type;
}

AMateria::AMateria(AMateria& old)
{
	this->type = old.type;
}

AMateria& AMateria::operator=(AMateria& old)
{
	this->type = old.type;
	return *this;
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}

std::string const & AMateria::getType() const
{
	return type;
}

AMateria::~AMateria(){}