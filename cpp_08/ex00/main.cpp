#include "easyfind.hpp"
#include <list>
#include <vector>

int main()
{
	try
	{
		std::cout << "-> use easyfind() on an std::vector<int> with existed value:" << std::endl;
		std::vector<int> vc;
		vc.push_back(15);
		vc.push_back(15);
		vc.push_back(42);
		vc.push_back(12);
		vc.push_back(23);
		int position = ::easyfind(vc, 42);
		std::cout << "the value 42 is found at position: " << position << std::endl;

		std::cout << "\n-> use easyfind() on an std::list<int> with non-existed value:" << std::endl;
		std::list<int> lst;
		lst.push_back(142);
		lst.push_back(142);
		lst.push_back(142);
		position = ::easyfind(lst, 42);
		std::cout << "the value 42 is found at position: " << position << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}