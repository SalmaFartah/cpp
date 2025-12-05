#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
protected:
	std::string type;
public:
	WrongAnimal();
	WrongAnimal( WrongAnimal &old );
	WrongAnimal& operator=( WrongAnimal& old );
	void makeSound() const;
	std::string getType() const;
	~WrongAnimal();
};

#endif