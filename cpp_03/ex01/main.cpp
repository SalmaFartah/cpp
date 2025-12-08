#include "ScavTrap.hpp"

int main()
{
	std::string GREEN  = "\033[32m";
    std::string ORANGE = "\033[38;5;208m";
    std::string RESET  = "\033[0m";


    std::cout << GREEN << "=== ScavTrap demo start ===\n\n";

    {
        std::cout << ORANGE << "Creating ScavTrap 'SCAV' (observe construction chaining):\n" << RESET;
        ScavTrap scav("SCAV");

        std::cout << ORANGE << "\nTest ScavTrap actions:\n" << RESET;
        scav.guardGate();
        scav.attack("SCAV_2");
        scav.takeDamage(30);
        scav.beRepaired(15);

        std::cout << ORANGE << "\nLeaving scope (ScavTrap will be destroyed, observe destructor chaining):\n" << RESET;
    }

    std::cout << GREEN << "\n=== ScavTrap demo end ===\n" << RESET;
    return 0;
}
