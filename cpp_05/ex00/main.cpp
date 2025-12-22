#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat obj("bure", 1);
		std::cout << obj;
		obj.grade_decrement();
		std::cout << obj;
		obj.grade_increment();
		std::cout << obj;
		obj.grade_increment();
		std::cout << obj;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
