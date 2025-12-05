#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure()
{
    type = "Cure";
}

Cure::Cure( Cure& old )
{
    type = old.type;
}

Cure& Cure::operator=( Cure& old )
{
    type = old.type;
    return *this;
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "’s wounds *\n";
}

AMateria* Cure::clone() const
{
    return new Cure;
}

Cure::~Cure(){}