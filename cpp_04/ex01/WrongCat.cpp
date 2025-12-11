#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << "WrongCat born! 😼 I still hate Mondays." << std::endl;
}

WrongCat::WrongCat( const WrongCat& old ) : WrongAnimal( old )
{
	std::cout << "WrongCat copy! 😼 A shadow twin appears... silently." << std::endl;
}

WrongCat& WrongCat::operator=( const WrongCat& old )
{
	WrongAnimal::operator=(old);
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "Meow? No... I'm broken! 😿💔" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat vanished! 👻 Not even wrong anymore." << std::endl;
}
