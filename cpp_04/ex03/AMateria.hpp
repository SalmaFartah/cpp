#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>
class ICharacter;

class AMateria
{
protected:
	std::string type;
public:
	AMateria();//-------------------------DEFAULT_CONSTRUCTOR
	AMateria(AMateria& old);//------------COPY_CONSTRUCTOR
	AMateria& operator=(AMateria& old);//-COPY_ASSIGN
	AMateria(std::string const & type);//-PARAMETRIZED_CTOR

	std::string const & getType() const; //Returns the materia type

	virtual AMateria* clone() const = 0; //Pure function
	virtual void use(ICharacter& target);
	virtual ~AMateria();
};

#endif