#include "iter.hpp"

void myFunc(char& ch)
{
	ch = std::toupper(ch);
}

void intFunc(const int& nb)
{
	std::cout << nb << " ";
}

int main()
{
	{
		std::cout << "-> try to pass an array of charachters to iter function:" << std::endl;
		char arr[] = "abcd";
		iter(arr, 4, myFunc);
		std::cout << arr << std::endl;
	}

	{
		std::cout << "-> try to pass an array of integers to iter function:" << std::endl;
		int arr[] = {145, 65, 0, -98, 99};
		iter(arr, 5, intFunc);
		std::cout << std::endl;
	}
}
