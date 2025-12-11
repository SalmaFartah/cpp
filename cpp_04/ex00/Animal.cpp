#include "Animal.hpp"

Animal::Animal() // DEFAULT CTOR
{
	type = "Animal";
	std::cout << "Animal constructor called! 🐾 Rawr?" << std::endl;
}

Animal::Animal( const Animal& old ) // COPY CTOR
{
	type = old.type;
	std::cout << "Animal copy constructor! 🧬 Cloning life..." << std::endl;
}

Animal& Animal::operator=( const Animal& old ) // COPY ASSIGNMENT
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

Animal::~Animal() // DESTRUCTOR
{
	std::cout << "Animal destructor called! 💀 Gone with the wind..." << std::endl;
}
