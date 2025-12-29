#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	std::string RESET  = "\033[0m";
	std::string ORANGE = "\033[38;5;208m";
	try
	{
		Bureaucrat myBureacrat("manager", 2);
		Intern x;

		std::cout << ORANGE << "[Creating 'ShrubberyCreationForm' with target 'garden']\n" << RESET;
		AForm* ptr = x.makeForm("shrubbery creation", "garden");
		if (ptr)
		{
			myBureacrat.signForm(*ptr);
			myBureacrat.executeForm(*ptr);
			delete ptr;
		}

		std::cout << ORANGE << "\n[Creating 'RobotomyRequestForm' with target 'cook machine']\n" << RESET;
		ptr = x.makeForm("robotomy request", "cook machine");
		if (ptr)
		{
			myBureacrat.signForm(*ptr);
			myBureacrat.executeForm(*ptr);
			delete ptr;
		}

		std::cout << ORANGE << "\n[Creating 'PresidentialPardonForm' with target 'elini']\n" << RESET;
		ptr = x.makeForm("presidential pardon", "elini");
		if (ptr)
		{
			myBureacrat.signForm(*ptr);
			myBureacrat.executeForm(*ptr);
			delete ptr;
		}

		std::cout << ORANGE << "\n[Trying to create a form with an invalid name 'invalid name']\n" << RESET;
		ptr = x.makeForm("invalid name", "INVALID");
		if (ptr)
		{
			myBureacrat.signForm(*ptr);
			myBureacrat.executeForm(*ptr);
			delete ptr;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << "An exception occurred: " << e.what() << '\n';
	}

	return 0;
}