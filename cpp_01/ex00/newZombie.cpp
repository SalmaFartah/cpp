#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
    Zombie *Zz = new (std::nothrow) Zombie(name);
    if (!Zz)
        return NULL;
    return Zz;
}
