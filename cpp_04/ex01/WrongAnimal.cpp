#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	type = "WrongAnimal";
	std::cout << "WrongAnimal created! 🚨 Something feels off..." << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal& old )
{
	type = old.type;
	std::cout << "WrongAnimal copy! 🧬 Cloning chaos..." << std::endl;
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal& old )
{
	type = old.type;
	return *this;
}

void WrongAnimal::makeSound() const
{
	std::cout << "?? What even is sound? 🌀" << std::endl;
}


std::string WrongAnimal::getType() const
{
	return type;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destroyed! 🧩 Puzzle incomplete..." << std::endl;
}
