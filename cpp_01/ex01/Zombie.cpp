#include "Zombie.hpp"

Zombie::Zombie(){}

Zombie::Zombie(std::string str)
{
    name = str;
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << name << " is now gone.. !" << std::endl;
}

void Zombie::announce( void )
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::_set_(std::string str)
{
    name = str;
}
