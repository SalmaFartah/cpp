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
	Zombie(std::string str);
	void _set_(std::string str);
	Zombie(){};
	~Zombie();
};

Zombie* zombieHorde( int N, std::string name );

#endif