#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>
#include <new>

class Zombie
{
private:
	std::string name;
public:
	void announce( void );
	void _set_(std::string str);
	Zombie(std::string str);
	Zombie();
	~Zombie();
};

Zombie* zombieHorde( int N, std::string name );

#endif