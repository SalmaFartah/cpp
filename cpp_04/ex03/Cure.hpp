#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{

public:
	Cure();
	Cure(Cure& old);
	Cure& operator=(Cure& old);

	virtual AMateria* clone() const;
	void use(ICharacter& target);
	~Cure();
};

#endif