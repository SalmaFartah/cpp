#ifndef DOG_HPP
#define DOG_HPP


#include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog(); // CTOR
	Dog( const Dog &old ); // COPY CTRO
	Dog& operator=( const Dog& old ); // COPY ASSIGN
	void makeSound() const; // overriden
	~Dog(); // DTOR
};

#endif
