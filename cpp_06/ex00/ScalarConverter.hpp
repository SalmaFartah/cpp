#pragma once
#include <string>
#include <iostream>

class ScalarConverter
{
	ScalarConverter();
public:
	ScalarConverter( const ScalarConverter& old );
	ScalarConverter& operator=( const ScalarConverter& old );
	static void convert(const std::string& str);
	~ScalarConverter();
};
