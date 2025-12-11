#include "ClapTrap.hpp"

int main()
{
	std::string GREEN  = "\033[32m";
    std::string ORANGE = "\033[38;5;208m";
    std::string RESET  = "\033[0m";

    std::cout << GREEN << "=== ClapTrap demo start ===\n\n" << RESET;

    {
        std::cout << ORANGE << "Creating ClapTrap 'Bob':\n" << RESET;
        ClapTrap bob("Bob");// HP = 10, EP = 10, AD = 0

        std::cout << ORANGE  << "\nSimple actions:\n" << RESET;
        bob.attack("AMY");// HP = 10, EP = 9, AD = 0
        bob.takeDamage(5);// HP = 5, EP = 9, AD = 0
        bob.beRepaired(3);// HP = 8, EP = 8, AD = 0

        std::cout << ORANGE << "\nDeplete energy by attacking until energy runs out:\n" << RESET;
        for (int i = 1; i <= 9; i++)
        {
            std::cout << i << ": ";
            bob.attack("dummy target");
        }

        std::cout << ORANGE << "\nInflict fatal damage and try actions with 0 hit points:\n" << RESET;
        bob.takeDamage(100);
        bob.attack("someone");
        bob.beRepaired(5);

        std::cout << ORANGE << "\nLeaving scope — Bob will be destroyed:\n" << RESET;
    }

    std::cout << GREEN << "\n=== ClapTrap demo end ===\n" << RESET;
    return 0;
}
