#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("presidential pardon", 25, 5){}

PresidentialPardonForm::PresidentialPardonForm( const std::string& newTarget) : AForm("presidential pardon", 25, 5)
{
    target = newTarget;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& old ) : AForm(old)
{
    target = old.target;
}

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm& old )
{
    AForm::operator=(old);
    target = old.target;
    return *this;
}

void PresidentialPardonForm::execute( Bureaucrat const & executor ) const
{
    if (!is_signed())
        throw FormNotSigned();
    if (executor.getGrade() > this->getExecuteGrade())
        throw GradeTooLowException();
    std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(){}