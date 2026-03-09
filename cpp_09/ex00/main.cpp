#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		return std::cerr << "Error: could not open file.\n", 1;
	try
	{
		BitcoinExchange obj(av[1]);
		obj.build();
	}
	catch (std::exception& b)
	{
		std::cerr << b.what() << std::endl;
	}
}
