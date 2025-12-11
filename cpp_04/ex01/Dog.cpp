#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	std::cout << "Dog constructor called! 🐶 Woof! I need snacks!" << std::endl;
	DogBrain = new Brain();
}

Dog::Dog(  const Dog& old ) : Animal( old )
{
	std::cout << "Dog copy constructor! 🐕 A puppy is born !" << std::endl;
	DogBrain = new Brain(*old.DogBrain);
}

Dog& Dog::operator=(  const Dog& old )
{
	if (this != &old)
	{
		Animal::operator=(old);
		delete DogBrain;
		DogBrain = new Brain(*old.DogBrain);
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Woof! Woof! 🐾🍖" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called! 😭 No more treats... zZz" << std::endl;
	delete DogBrain;
}
