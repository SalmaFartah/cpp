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

bool charChecker( const std::string& str )
{
    
}

void ScalarConverter::convert( const std::string& str )
{
    std::cout << str.size() << std::endl;

}

ScalarConverter::~ScalarConverter()
{
}
