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
	WrongAnimal( const WrongAnimal &old );
	WrongAnimal& operator=( const WrongAnimal& old );
	void makeSound() const;
	std::string getType() const;
	~WrongAnimal();
};

#endif