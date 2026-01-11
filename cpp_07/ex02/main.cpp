#include "Array.hpp"

void leaks()
{
	system("leaks -q Array");
}

int main()
{
	try
	{
		// atexit(leaks);
		Array<int> b;
		std::cout << "b size: " << b.size() << std::endl;
		b[0] = 15;
		std::cout << "b[0] bfr copy: " << b[0] << std::endl;
		Array<int> v(b);
		v[0] = 8;
		std::cout << "v size: " << b.size() << std::endl;
		std::cout << "b[0] aftr copy: " << b[0] << std::endl;
		std::cout << "v[0] aftr copy: " << v[0] << std::endl;
		v = b;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
