#include "AMateria.hpp"
#include "Character.hpp"
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
	if (target.getName() == "ice")
		std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
	if (target.getName() == "cure")
		std::cout << "* heals " << target.getName() << "’s wounds *\n";		
}

std::string const & AMateria::getType() const
{
	return type;
}

AMateria::~AMateria(){}