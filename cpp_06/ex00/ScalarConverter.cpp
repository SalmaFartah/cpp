#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter( const ScalarConverter& old )
{
    (void)old;
}

ScalarConverter& ScalarConverter::operator=( const ScalarConverter& old )
{
    (void)old;
    return *this;
}

std::string TrimStr(const std::string& str)
{
    size_t start = str.find_first_not_of("	 ");
    if (start == std::string::npos)
        return "";
    size_t end = str.find_last_not_of("	 ");
    return str.substr(start, end - start + 1);
}

bool charChecker( std::string& str )
{
    if (str.length() == 1 && !std::isdigit(str[0]))
    {
        std::cout << "char: \'" << str[0] << "\'" << std::endl;
        std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
        std::cout << "float: " << static_cast<float>(str[0]) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(str[0]) << ".0" << std::endl;
        return true;
    }
    return false;
}

bool intChecker( std::string& str )
{   
    std::string cut(str);
    if (str[0] == '-' || str[0] == '+')
        cut = str.substr(1, str.length());
    if (cut.find_first_not_of("0123456789") == std::string::npos)
    {
        int r = std::atoi(str.c_str());

        std::cout << "char: ";
        if (r >= 32 && r <= 126)
            std::cout << static_cast<char>(r) << std::endl;
        else if ((r >= 0 && r <= 31) || r == 127)
            std::cout << "Non displayable" << std::endl;	
        else
            std::cout << "impossible" << std::endl;

        std::cout << "int: " << r << std::endl;

        std::cout << "float: " << static_cast<float>(r) << std::endl;

        std::cout << "double: " << static_cast<double>(r) << std::endl;
        return true;
    }
    return false;
}

void ScalarConverter::convert( std::string str )
{
    if (charChecker(str))
        return ;

    str = TrimStr(str);
    if (str.empty())
        return ;
    if (intChecker(str))
        return ;
}

ScalarConverter::~ScalarConverter()
{
}
