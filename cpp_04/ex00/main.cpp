#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	std::string ORANGE = "\033[38;5;208m";
	std::string RESET  = "\033[0m";

	std::cout << ORANGE << "-------------CORRECTANIMALS----------------" << RESET << std::endl;
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		delete meta;
		delete j;
		delete i;
	}
	std::cout << ORANGE << "---------------WRONGANIMALS------------------" << RESET << std::endl;
	{
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the wronganimal sound!
		meta->makeSound();
		delete meta;
		delete i;
	}

	return 0;
}
