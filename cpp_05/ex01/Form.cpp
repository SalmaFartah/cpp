#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Default"), GradeSign(150), GradeExecute(150)
{
    signed_ = false;
}

Form::Form( std::string const newName, int const gs, int const ge ) : name(newName), GradeSign(gs), GradeExecute(ge)
{
    signed_ = false;
    if (gs < 1 || ge < 1)
        throw GradeTooHighException();
    else if (gs > 150 || ge > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &  old ) : name(old.name), GradeSign(old.GradeSign), GradeExecute(old.GradeExecute)
{
    signed_ = old.signed_;
}

Form& Form::operator=( const Form & old )
{
    signed_ = old.signed_;
    return *this;
}

int Form::getGradeExecute() const
{
    return GradeExecute;
}

int Form::getGradeSign() const
{
    return GradeSign;
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
    if (bureacrat.getGrade() > this->getGradeSign())
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
    out << "the Form \"" << form.getName() << "\" requires GradeToSign [ " << form.getGradeSign() << " ] and GradeToExecute [ " << form.getGradeExecute() << " ] is ";
    if (form.is_signed())
        std::cout << "[✅ SIGNED]";
    else
        std::cout << "[❌ NOT SIGNED]";
    return out;
}

Form::~Form(){}
