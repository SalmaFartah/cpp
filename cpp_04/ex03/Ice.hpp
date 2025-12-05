#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(Ice& old);
		Ice& operator=(Ice& old);
	
		AMateria* clone() const;
		void use(ICharacter& target);
		~Ice();
};

#endif