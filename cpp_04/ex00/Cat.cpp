#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	std::cout << "Cat constructor called! 🐱 Meow. I approve this message." << std::endl;
}

Cat::Cat( Cat& old ) : Animal( old )
{
	std::cout << "Cat copy constructor! 😼 A shadow clone appears... silently." << std::endl;
}

Cat& Cat::operator=( Cat& old )
{
	Animal::operator=(old);
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meow~ 🐾🥛" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called! 🙀 Time for a 20-hour nap..." << std::endl;
}
