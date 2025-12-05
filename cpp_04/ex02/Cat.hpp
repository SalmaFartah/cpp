#ifndef CAT_HPP
#define CAT_HPP


#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *CatBrain;
	public:
		Cat();
		Cat( Cat &old );
		Cat& operator=( Cat& old );
		void makeSound() const;
		~Cat();
};

#endif
