#include "ScalarConverter.hpp"
#define RED "\e[0;31m"
#define RESET "\e[0m"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << RED << "Enter one argument !" << RESET << std::endl;
        return 1;
    }
    ScalarConverter::convert(av[1]);
}


// #include <iostream>
// #include <iomanip>

// int main() {
//     int value = 9999998;
//     std::cout << static_cast<float>(value) << std::endl;
//     return 0;
// }