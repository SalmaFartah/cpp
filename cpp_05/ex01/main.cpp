#include "Form.hpp"

int main()
{
	try
	{
		Form obj("bure", 1, 156);
		std::cout << obj;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
