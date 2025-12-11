#include "Animal.hpp"

Animal::Animal()
{
	type = "Animal";
	std::cout << "Animal constructor called! 🐾 Rawr?" << std::endl;
}

Animal::Animal( const Animal& old )
{
	type = old.type;
	std::cout << "Animal copy constructor! 🧬 Cloning life..." << std::endl;
}

Animal& Animal::operator=( const Animal& old )
{
	type = old.type;
	return *this;
}

void Animal::makeSound() const
{
	std::cout << "*Unknown animal noise* 🤔❓" << std::endl;
}

std::string Animal::getType() const
{
	return type;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called! 💀 Gone with the wind..." << std::endl;
}
