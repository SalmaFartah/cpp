#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		return std::cerr << "bad argument!" << std::endl, 1;
	try
	{
    	RPN obj(av[1]);
		obj.processRpn();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}
