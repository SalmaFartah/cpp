#include "ScalarConverter.hpp"
#include "climits"
#include <cmath>
#include <string>

int main()
{
    // ScalarConverter::convert(".");
    char b = 122.9f;
    std::string str = "4294967295";
    int t = atoi(str.c_str());

    // float g = 'A';
    // int h = 4294967295;
    // int h = -2147483649;
    std::cout << t << std::endl;
}