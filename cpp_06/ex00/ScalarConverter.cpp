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

void charChecker( std::string& str )
{
	if (str.length() == 1 && !std::isdigit(str[0]) && std::isprint(str[0]))
	{
		std::cout << "char: \'" << str[0] << "\'" << std::endl;
		std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(str[0]) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(str[0]) << std::endl;
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
	char *check;
	errno = 0;

	long number = std::strtol(str.c_str(), &check, 10);
	if (*check || errno == ERANGE || number > INT_MAX || number < INT_MIN)
		return ;
	toChar(number);
	std::cout << "int: " << static_cast<int>(number) << std::endl;

	std::cout << "float: " << static_cast<float>(number) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(number) << std::endl;
	throw std::exception();
}

void floatChecker( std:: string& str )
{
	char *check;
	errno = 0;

	double number = std::strtod(str.c_str(), &check);
	if (!*check || *check != 'f' || check[1] || str.find(".") == std::string::npos)
		return ;

	toChar(number);
	if (errno == ERANGE || number > INT_MAX || number < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(number) << std::endl;

	float floatP = static_cast<float>(number);

	std::cout << "float: " << floatP << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(floatP) << std::endl;
	throw std::exception();
}

void doubleChecker(std::string& str)
{
	char *check;
	errno = 0;

	double number = std::strtod(str.c_str(), &check);
	if (*check || str.find(".") == std::string::npos)
		return ;
	toChar(number);
	if (errno == ERANGE || number > INT_MAX || number < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(number) << std::endl;

	std::cout << "float: " << static_cast<float>(number) << "f" << std::endl;
	std::cout << "double: " << number << std::endl;
	throw std::exception();
}

void limitsCheck(std::string& str)
{
	if (str == "nanf" || str == "-inff" || str == "+inff")
	{
		std::cout << "char: impossible\nint: impossible\nfloat: " << str << "\ndouble: " << str.substr(0, str.length() - 1) << std::endl;	
		throw std::exception();
	}
	else if (str == "nan" || str == "-inf" || str == "+inf")
	{
		std::cout << "char: impossible\nint: impossible\nfloat: " << str + "f" << "\ndouble: " << str << std::endl;	
		throw std::exception();
	}
}

std::string TrimStr(const std::string& str)
{
	size_t start = str.find_first_not_of(" \t\n\r\f\v");
	if (start == std::string::npos)
		return "";
	size_t end = str.find_last_not_of(" \t\n\r\f\v");
	return str.substr(start, end - start + 1);
}

void ScalarConverter::convert( std::string str )
{
	try
	{
		std::cout << std::fixed << std::setprecision(1);
		charChecker(str);
		str = TrimStr(str);
		if (!str.empty())
		{
			intChecker(str);
			floatChecker(str);
			doubleChecker(str);
			limitsCheck(str);
		}
	}
	catch(const std::exception& e)
	{
		return ;
	}
	std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
}

ScalarConverter::~ScalarConverter(){}

