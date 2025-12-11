#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	std::cout << "Cat constructor called! 🐱 Meow. I approve this message." << std::endl;
	CatBrain = new Brain();
}

Cat::Cat(  const Cat& old ) : Animal( old )
{
	std::cout << "Cat copy constructor! 😼 A shadow clone appears... silently." << std::endl;
	CatBrain = new Brain(*old.CatBrain);
}

Cat& Cat::operator=(  const Cat& old )
{
	if (this != &old)
	{
		delete CatBrain;
		CatBrain = new Brain(*old.CatBrain);
		Animal::operator=(old);
	}
	
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meow~ 🐾🥛" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called! 🙀 Time for a 20-hour nap..." << std::endl;
	delete CatBrain;
}
