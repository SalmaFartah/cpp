#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
protected:
	std::string type;
public:
	Animal(); // CTOR
	Animal( const Animal &old ); // COPY CTOR
	Animal& operator=( const Animal& old ); // COPY ASSIGN
	virtual void makeSound() const;
	std::string getType() const;
	virtual ~Animal(); // DTOR
};

#endif
