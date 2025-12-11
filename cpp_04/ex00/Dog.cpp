#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	std::cout << "Dog constructor called! 🐶 Woof! I need snacks!" << std::endl;
}

Dog::Dog( const Dog& old ) : Animal( old )
{
	std::cout << "Dog copy constructor! 🐕 A puppy is born !" << std::endl;
}

Dog& Dog::operator=( const Dog& old )
{
	Animal::operator=(old);
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Woof! Woof! 🐾🍖" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called! 😭 No more treats... zZz" << std::endl;
}
