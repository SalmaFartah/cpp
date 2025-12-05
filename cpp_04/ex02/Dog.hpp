#ifndef DOG_HPP
#define DOG_HPP


#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *DogBrain;
	public:
		Dog();
		Dog( Dog &old );
		Dog& operator=( Dog& old );
		void makeSound() const;
		~Dog();
};

#endif
