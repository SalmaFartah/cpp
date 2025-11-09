#include "Zombie.hpp"

int main()
{
    randomChump("MyZombie");

    Zombie *Zz = newZombie("2ndZombie");
    Zz->announce();
    delete(Zz);
}
