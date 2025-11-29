#include "ClapTrap.hpp"

int main()
{
	std::string GREEN  = "\033[32m";
    std::string ORANGE = "\033[38;5;208m";
    std::string RESET  = "\033[0m";


    std::cout << GREEN << "=== ClapTrap demo start ===\n\n" << RESET;

    {
        std::cout << ORANGE << "Creating ClapTrap 'Bob':\n" << RESET;
        ClapTrap bob("Bob");

        std::cout << ORANGE  << "\nSimple actions:\n" << RESET;
        bob.attack("a wooden crate");
        bob.takeDamage(5);
        bob.beRepaired(3);

        std::cout << ORANGE << "\nDeplete energy by attacking until energy runs out:\n" << RESET;
        for (int i = 0; i < 9; ++i)
        {
            std::cout << "Attempt " << (i + 1) << ": ";
            bob.attack("dummy target");
        }

        std::cout << ORANGE << "\nInflict fatal damage and try actions with 0 hit points:\n" << RESET;
        bob.takeDamage(100);
        bob.attack("someone");
        bob.beRepaired(5);

        std::cout << ORANGE << "\nCreate another ClapTrap 'Alice' to test repairs costing energy:\n" << RESET;
        ClapTrap alice("Alice");
        alice.takeDamage(8);
        std::cout << ORANGE << "Alice repairs repeatedly (each repair costs 1 energy):\n" << RESET;
        for (int i = 0; i < 11; ++i)
        {
            std::cout << "Repair attempt " << (i + 1) << ": ";
            alice.beRepaired(2);
        }

        std::cout << ORANGE << "\nLeaving scope — Bob and Alice will be destroyed (observe destructor messages):\n" << RESET;
    }

    std::cout << GREEN << "\n=== ClapTrap demo end ===\n" << RESET;
    return 0;
}