#ifndef DOG_HPP
#define DOG_HPP


#include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog();
	Dog( Dog &old );
	Dog& operator=( Dog& old );
	void makeSound() const;
	~Dog();
};

#endif
