#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

class Character : public ICharacter
{
private:
	std::string name;
public:
	AMateria *slots[4];
	Character();
	Character( Character& old );
	Character( std::string Name);
	Character& operator=( Character& old );

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
	~Character();
};

#endif
