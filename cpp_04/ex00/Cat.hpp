#ifndef CAT_HPP
#define CAT_HPP


#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat();
	Cat( Cat &old );
	Cat& operator=( Cat& old );
	void makeSound() const;
	~Cat();
};

#endif
