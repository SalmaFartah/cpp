#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie	*Zz = new (std::nothrow) Zombie[N];
	if (!Zz)
		return (NULL);
	for (int i = 0; i < N; i++)
		Zz[i]._set_(name);

	return Zz;
}
