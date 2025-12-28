#include "Bureaucrat.hpp"

int main()
{
    std::string GREEN  = "\033[32m";
    std::string RESET  = "\033[0m";
    std::string RED    = "\033[31m";
    std::string ORANGE = "\033[38;5;208m";

    try
    {
        std::cout << GREEN << "==CREATE BUREAUCRAT OUT OF RANGE==" << std::endl << RESET;
        Bureaucrat s("OutOfRange", 999);
    }
    catch( std::exception& e )
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << GREEN << "==INCREMENT/DECREMENT GRADE==" << std::endl << RESET;
        Bureaucrat obj("kara", 1);
        std::cout << ORANGE << "Initial Bureaucrat state:\n" << RESET << obj << std::endl;

        obj.decrementGrade();
        std::cout << ORANGE << "After decrementing grade:\n" << RESET << obj << std::endl;

        obj.incrementGrade();
        std::cout << ORANGE << "After incrementing grade:\n" << RESET << obj << std::endl;

        obj.incrementGrade();
        std::cout << ORANGE << "After second increment attempt:\n" << RESET << obj << std::endl;
    }
    catch( std::exception& e )
    {
        std::cerr << RED << "An exception occurred:\n" << RESET << e.what() << '\n';
    }
}
