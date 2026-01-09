#pragma once
#include <string>
#include <iostream>
#include <climits>
#include <iomanip>
#include <cerrno>
#include <cstdlib>

#define RED "\e[0;31m"
#define RESET "\e[0m"

class ScalarConverter
{
	ScalarConverter();// private ctor to make the class not instantiable..
public:
	ScalarConverter( const ScalarConverter& old );
	ScalarConverter& operator=( const ScalarConverter& old );
	static void convert( std::string str );
	~ScalarConverter();
};
