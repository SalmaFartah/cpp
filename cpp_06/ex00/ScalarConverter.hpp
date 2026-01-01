#pragma once
#include <string>
#include <iostream>

class ScalarConverter
{
	ScalarConverter();// private ctor to make the class not instantiable..
	void charChecker( const std::string& str );
	void intChecker( const std::string& str );
	class intFound : public std::exception{};
	class charFound : public std::exception{};
public:
	ScalarConverter( const ScalarConverter& old );
	ScalarConverter& operator=( const ScalarConverter& old );
	static void convert(const std::string& str);
	~ScalarConverter();
};
