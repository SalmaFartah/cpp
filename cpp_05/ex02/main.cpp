#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	try
	{
		Bureaucrat a("BURE", 1);
		ShrubberyCreationForm sForm("file");
		sForm.beSigned(a);
		sForm.execute(a);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
