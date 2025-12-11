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
		Dog( const Dog &old );
		Dog& operator=( const Dog& old );
		void makeSound() const;
		~Dog();
};

#endif
