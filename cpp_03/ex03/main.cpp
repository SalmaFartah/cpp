#include "DiamondTrap.hpp"

int main()
{
    std::string GREEN  = "\033[32m";
    std::string ORANGE = "\033[38;5;208m";
    std::string RESET  = "\033[0m";

    std::cout << GREEN << "the DiamondTrap KAN will be created watch construction chaining: " << RESET << std::endl;
    DiamondTrap a("KAN");
    std::cout << ORANGE << "\n-- after construction --\n" << RESET;
    a.whoAmI();

    std::cout << ORANGE << "\n-- basic actions --\n" << RESET;
    a.attack("Bandit");
    a.takeDamage(25);
    a.beRepaired(15);

    std::cout << ORANGE << "\n-- frag/scav behaviours --\n" << RESET;
    a.highFivesGuys();
    a.guardGate();

    return 0;
}
