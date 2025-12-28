#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    std::string RESET  = "\033[0m";
	std::string ORANGE = "\033[38;5;208m";
    try
    {
        std::cout << ORANGE << "==ATTEMPT TO EXECUTE ROBOTOMYREQUESTFORM MULTIPLE TIME==" << RESET << std::endl;
        Bureaucrat MyB("JOHN", 20);
        RobotomyRequestForm rbtForm("Alice");
        MyB.signForm(rbtForm);
        MyB.executeForm(rbtForm);
        MyB.executeForm(rbtForm);
        MyB.executeForm(rbtForm);
        MyB.executeForm(rbtForm);
        MyB.executeForm(rbtForm);

        std::cout << ORANGE << "\nEXECUTING PRESIDENTIALPARDONFORM..." << RESET << std::endl;
        PresidentialPardonForm prdForm("Bob");
        MyB.signForm(prdForm);
        MyB.executeForm(prdForm);

        std::cout << ORANGE << "\nEXECUTING SHRUBBERYCREATIONFORM (CREATES ASCII ART)..." << RESET << std::endl;
        ShrubberyCreationForm shForm("Charlie");
        MyB.signForm(shForm);
        MyB.executeForm(shForm);
		
        std::cout << ORANGE << "\nATTEMPT TO EXECUTE NOT SIGNED FORM" << RESET << std::endl;
		ShrubberyCreationForm NotSign("NOTSIGN");
		MyB.executeForm(NotSign);

    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}