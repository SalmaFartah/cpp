#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
protected:
	std::string type;
public:
	Animal();
	Animal( Animal &old );
	Animal& operator=( Animal& old );
	virtual void makeSound() const = 0;
	std::string getType() const;
	virtual ~Animal();
};

#endif