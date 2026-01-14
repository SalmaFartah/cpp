#include "Array.hpp"

int main()
{
	try
	{
		std::cout << "create array of integers b: " << std::endl;
		Array<int> b(6);
		std::cout << "b size: " << b.size() << std::endl;
		b[0] = 15;
		std::cout << "b[0] bfr copy: " << b[0] << std::endl;

		std::cout << "create another array of integers v copied form b: " << std::endl;
		Array<int> v(b);
		v[0] = 8;
		std::cout << "v size: " << b.size() << std::endl;
		std::cout << "b[0] aftr copy: " << b[0] << std::endl;
		std::cout << "v[0] aftr copy: " << v[0] << std::endl;
		
		std::cout << "try to create array of strings str:" << std::endl;
		Array<std::string> str(2);
		str[0] = "test";
		str[1] = "hello";
		str[2] = "d";
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
