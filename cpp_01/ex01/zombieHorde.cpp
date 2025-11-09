#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie	*Zz = new Zombie[N];

	for (int i = 0; i < N; i++)
		Zz[i]._set_(name);
	
	return Zz;
}
