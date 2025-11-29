#include "Harl.hpp"

int main(int ac, char *av[])
{
    if (ac != 2)
        return std::cout << "[! The program takes one argument ]" << std::endl, 1;
    
    Harl obj;
    obj.complain(av[1]);
}