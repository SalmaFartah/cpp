#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("robotomy request", 72, 45){}

RobotomyRequestForm::RobotomyRequestForm( const std::string &newTarget ) : AForm("robotomy request", 72, 45)
{
    target = newTarget;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & old ) : AForm(old)
{
    target = old.target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm & old )
{
    AForm::operator=(old);
    target = old.target;
    return *this;
}

void RobotomyRequestForm::execute( Bureaucrat const & executor ) const
{
    if (!is_signed())
        throw FormNotSigned();
    if (executor.getGrade() > getExecuteGrade())
        throw GradeTooLowException();
    
    static int v;
    std::cout << "vroom vroom 🤖🛠️  ";
    if (v == 0)
    {
        v = 1;
        std::cout << "✅ " << target << " has been succesfully robotomized !" << std::endl;
        return ;
    }
    v = 0;
    std::cout << "❌ " << "robotomy FAILED !\n";
}

RobotomyRequestForm::~RobotomyRequestForm(){}