#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("unNamed"), SignGrade(150), ExecuteGrade(150)
{
    signed_ = false;
}

Form::Form( std::string const newName, int const gs, int const ge ) : name(newName), SignGrade(gs), ExecuteGrade(ge)
{
    signed_ = false;
    if (gs < 1 || ge < 1)
        throw GradeTooHighException();
    else if (gs > 150 || ge > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &  old ) : name(old.name), SignGrade(old.SignGrade), ExecuteGrade(old.ExecuteGrade)
{
    signed_ = old.signed_;
}

Form& Form::operator=( const Form & old )
{
    signed_ = old.signed_;
    return *this;
}

int Form::getExecuteGrade() const
{
    return ExecuteGrade;
}

int Form::getSignGrade() const
{
    return SignGrade;
}

const std::string Form::getName() const
{
    return name;
}

bool Form::is_signed() const
{
    return signed_;
}

void Form::beSigned(Bureaucrat& bureacrat)
{	
    if (signed_)
        throw FormAlreadySignedException();
    if (bureacrat.getGrade() > this->getSignGrade())
        throw GradeTooLowException();
    else
        signed_ = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Grade Too High !");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Grade Too Low !");
}

const char *Form::FormAlreadySignedException::what() const throw()
{
    return ("Form Already Signed");
}

std::ostream& operator<<(std::ostream& out, Form& form)
{
    out << "the Form \"" << form.getName() << "\" requires GradeToSign [ " << form.getSignGrade() << " ] and GradeToExecute [ " << form.getExecuteGrade() << " ] is ";
    if (form.is_signed())
        std::cout << "[✅ SIGNED]";
    else
        std::cout << "[❌ NOT SIGNED]";
    return out;
}

Form::~Form(){}
