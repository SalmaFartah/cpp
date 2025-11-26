#include "Zombie.hpp"

int main()
{
    randomChump("StackZombie");

    Zombie *Zz = newZombie("HeapZombie");
    if (Zz)
    {
        Zz->announce();
        delete(Zz);
    }
}
