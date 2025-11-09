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
	~Zombie();
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );
