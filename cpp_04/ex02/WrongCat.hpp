#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	WrongCat( WrongCat &old );
	WrongCat& operator=( WrongCat& old );
	void makeSound() const;
	~WrongCat();
};

#endif