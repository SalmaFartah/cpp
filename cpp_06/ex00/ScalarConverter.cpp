#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter( const ScalarConverter& old )
{
    (void)old;
}

ScalarConverter& ScalarConverter::operator=( const ScalarConverter& old )
{
    (void)old;
    return *this;
}

// bool charChecker( const std::string& str )
// {
//     if (str.length() == 1 && !std::isdigit(str[0]))
//     {
//         std::cout << "char: " << str[0] << std::endl;
//         std::cout << "int: " << str[0] - 48 << std::endl;
//     }
    
// }

// void ScalarConverter::convert( const std::string& str )
// {
//     std::cout << str.size() << std::endl;

// }

ScalarConverter::~ScalarConverter()
{
}
