#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice()
{
    type = "ice";
}

Ice::Ice( const Ice& old )
{
    type = old.type;
}

Ice& Ice::operator=( const Ice& old )
{
    type = old.type;
    return *this;
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}

AMateria* Ice::clone() const
{
    return new Ice;
}

Ice::~Ice(){}