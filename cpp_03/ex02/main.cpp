#include "FragTrap.hpp"

int main()
{
    std::string GREEN  = "\033[32m";
    std::string ORANGE = "\033[38;5;208m";
    std::string RESET  = "\033[0m";

    std::cout << GREEN << "=== FragTrap demo start ===\n\n";

    {
        std::cout << ORANGE << "Creating FragTrap 'Fraggy' (observe construction messages):" << RESET << std::endl;

        FragTrap frag("Fraggy");

        std::cout << ORANGE << "\nTest FragTrap actions:" << RESET << std::endl;

        frag.highFivesGuys();

        frag.attack("a wild enemy");

        frag.takeDamage(25);

        frag.beRepaired(10);

        std::cout << ORANGE << "\nLeaving scope (FragTrap will be destroyed, observe destructor chaining): " << RESET << "\n";
    }

    std::cout << GREEN << "\n=== FragTrap demo end ===\n";
    return 0;
}