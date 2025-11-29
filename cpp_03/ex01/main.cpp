#include "ScavTrap.hpp"

int main()
{
	std::string GREEN  = "\033[32m";
    std::string ORANGE = "\033[38;5;208m";
    std::string RESET  = "\033[0m";


    std::cout << GREEN << "=== ScavTrap demo start ===\n\n";

    {
        std::cout << ORANGE << "Creating ScavTrap 'Gatekeeper' (observe construction chaining):\n" << RESET;
        ScavTrap scav("Gatekeeper");

        std::cout << ORANGE << "\nExercise ScavTrap actions:\n" << RESET;
        scav.guardGate();                    // ScavTrap-specific ability
        scav.attack("an intruder");          // overridden by ScavTrap
        scav.takeDamage(30);                 // inherited from ClapTrap
        scav.beRepaired(15);                 // inherited from ClapTrap

        std::cout << ORANGE << "\nLeaving scope (ScavTrap will be destroyed, observe destructor chaining):\n" << RESET;
    }

    std::cout << GREEN << "\n=== ScavTrap demo end ===\n" << RESET;
    return 0;
}