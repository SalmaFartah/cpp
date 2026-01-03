#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << RED << "Enter one argument !" << RESET << std::endl;
        return 1;
    }
    ScalarConverter::convert(av[1]);
}
