#include "Zombie.hpp"
#include <unistd.h>

int main()
{
	Zombie *Zz;
	Zz = zombieHorde(4, "Test");
	for (size_t i = 0; i < 4; i++)
		Zz[i].announce();

	delete[] Zz;
}
