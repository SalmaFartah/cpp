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

void charChecker( std::string& str )
{
	if (str.length() == 1 && !std::isdigit(str[0]) && std::isprint(str[0]))
	{
		std::cout << "char: \'" << str[0] << "\'" << std::endl;
		std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(str[0]) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(str[0]) << ".0" << std::endl;
		throw std::exception();
	}
}

void toChar(int r)
{
	std::cout << "char: ";
	if (r >= 32 && r <= 126)
		std::cout << "\'" << static_cast<char>(r) << "\'" << std::endl;
	else if ((r >= 0 && r <= 31) || r == 127)
		std::cout << "Non displayable" << std::endl;	
	else
		std::cout << "impossible" << std::endl;
}

void intChecker( std::string& str )
{   
	std::string cut(str);
	if (str[0] == '-' || str[0] == '+')
		cut = str.substr(1, str.length());
	if (cut.find_first_not_of("0123456789") == std::string::npos)
	{
		long number = std::atol(str.c_str());
		if (number > INT_MAX || number < INT_MIN)
			return ;
		toChar(number);
		std::cout << "int: " << number << std::endl;

		std::cout << "float: " << static_cast<float>(number);
		if (str.length() < 7 || number == 0)
			std::cout << ".0";
		std::cout << "f" << std::endl;

		std::cout << "double: " << static_cast<double>(number);
		if (str.length() < 7 || number == 0)
			std::cout << ".0";
		std::cout << std::endl;
		throw std::exception();
	}
}

void floatChecker( std:: string& str )
{
	std::string cut(str);
	if (str[0] == '-' || str[0] == '+')
		cut = str.substr(1, str.length());

	if (str[str.length() - 1] == 'f')
		cut = str.substr(1, str.length() - 2);

	size_t start = cut.find_first_not_of("0123456789");
	size_t end = cut.find_last_not_of("0123456789");

	if (end == start && cut[start] == '.')
	{
		double r = std::atof(str.c_str());
		toChar(r);
		std::cout << "int: ";
		if (r > INT_MAX || r < INT_MIN)
			std::cout << "impossible" << std::endl;
		else
			std::cout << static_cast<int>(r) << std::endl;
		std::cout << "float: " << static_cast<float>(r) << "f" << std::endl;
		std::cout << "double: " << r << std::endl;
		throw std::exception();
	}
}

void ScalarConverter::convert( std::string str )
{
	try
	{
		charChecker(str);
		str = TrimStr(str);
		if (str.empty())
			return ;
		intChecker(str);
		floatChecker(str);
	}
	catch(const std::exception& e)
	{
		return ;
	}
}

ScalarConverter::~ScalarConverter()
{
}
