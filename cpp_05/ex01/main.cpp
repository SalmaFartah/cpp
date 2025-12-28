#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
    std::string GREEN  = "\033[32m";
    std::string RESET  = "\033[0m";
    try
    {
        Bureaucrat myBureaucrat("mark", 100);
        Form myForm("form", 20, 2);
        std::cout << GREEN << "==SIGN FORM REQUIRING 20 GRADE TO SIGN WITH GRADE(100)==" << std::endl << RESET;
        myBureaucrat.signForm(myForm);
    }
    catch( std::exception& e )
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Bureaucrat myBureaucrat("Alice", 4);
        Form MyForm("form", 6, 3);
        std::cout << GREEN << "==SHOW FORM INFORMATIONS==" << std::endl << RESET;
        std::cout << MyForm << std::endl;
        std::cout << GREEN << "==SIGNING FORM TWICE==" << std::endl << RESET;
        myBureaucrat.signForm(MyForm);
        myBureaucrat.signForm(MyForm);
    }
    catch( std::exception& e )
    {
        std::cerr << e.what() << '\n';
    }
}
