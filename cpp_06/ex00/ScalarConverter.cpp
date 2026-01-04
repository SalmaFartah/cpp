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

std::string to_string(int value)
{
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

void intChecker( std::string& str )
{
	char *check;
	errno = 0;

	long b = std::strtol(str.c_str(), &check, 10);
	if (*check)
		return ;
	toChar(b);
	if (errno == ERANGE || b > INT_MAX || b < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else	
		std::cout << "int: " << static_cast<int>(b) << std::endl;
	std::cout << "float: " << static_cast<float>(b);
	if (to_string(b).length() < 7)
		std::cout << ".0";
	std::cout << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(b);
	if (to_string(b).length() < 7)
		std::cout << ".0";
	std::cout << std::endl;
	throw std::exception();
}

void floatChecker( std:: string& str )
{
	char *check;
	errno = 0;

	double b = std::strtod(str.c_str(), &check);
	if (!*check || (*check && *check != 'f') || check[1] || str.find(".") == std::string::npos)
		return ;
	toChar(b);
	if (errno == ERANGE || b > INT_MAX || b < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(b) << std::endl;
	std::cout << "float: " << static_cast<float>(b);
	if ((b == static_cast<int>(b) && to_string(static_cast<int>(b)).length() < 7)
	|| (to_string(static_cast<int>(b)).length() == 5 && str[str.find(".") + 1] == '0'))
		std::cout << ".0";
	std::cout << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(b);
	if ((b == static_cast<int>(b) && to_string(static_cast<int>(b)).length() < 7)
	|| (to_string(static_cast<int>(b)).length() == 5 && str[str.find(".") + 1] == '0'))
		std::cout << ".0";
	std::cout << std::endl;
	throw std::exception();
}

void doubleChecker(std::string& str)
{
	char *check;
	errno = 0;

	double b = std::strtod(str.c_str(), &check);
	if (*check || str.find(".") == std::string::npos)
		return ;
	toChar(b);
	if (errno == ERANGE || b > INT_MAX || b < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(b) << std::endl;
	std::cout << "float: " << static_cast<float>(b);
	if ((b == static_cast<int>(b) && to_string(static_cast<int>(b)).length() < 7)
	|| (to_string(static_cast<int>(b)).length() == 5 && str[str.find(".") + 1] == '0'))
		std::cout << ".0";
	std::cout << "f" << std::endl;
	std::cout << "double: " << b;
	if ((b == static_cast<int>(b) && to_string(static_cast<int>(b)).length() < 7)
	|| (to_string(static_cast<int>(b)).length() == 5 && str[str.find(".") + 1] == '0'))
		std::cout << ".0";
	std::cout << std::endl;
	throw std::exception();
}

void limitsCheck(std::string& str)
{
	if (str == "nanf" || str == "-inff" || str == "+inff" || str == "inff")
	{
		std::cout << "char: impossible\nint: impossible\nfloat: " << str << "\ndouble: " << str.substr(0, str.length() - 1) << std::endl;	
		throw std::exception();
	}
	else if (str == "nan" || str == "-inf" || str == "+inf" || str == "inf")
	{
		std::cout << "char: impossible\nint: impossible\nfloat: " << str + "f" << "\ndouble: " << str << std::endl;	
		throw std::exception();
	}
}

void ScalarConverter::convert( std::string str )
{
	try
	{
		charChecker(str);
		if (str.empty())
			return ;
		intChecker(str);
		floatChecker(str);
		doubleChecker(str);
		limitsCheck(str);
	}
	catch(const std::exception& e)
	{
		return ;
	}
	std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
}
