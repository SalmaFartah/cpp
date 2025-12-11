#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#include "IMateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria *slots[4];
public:
	MateriaSource();
	MateriaSource(const MateriaSource& old);
	MateriaSource& operator=( const MateriaSource& old );
	~MateriaSource();
	void learnMateria(AMateria *m);
	AMateria* createMateria(std::string const & type);
};

#endif