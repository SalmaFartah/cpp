#include "iter.hpp"

void f(char arr[], const int size)
{
	for (int i = 0; i < size; i++)
		arr[i] = std::toupper(arr[i]);	
}

int main()
{
	char arr[] = "abcd";
	iter(arr, 4, f);
}