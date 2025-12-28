#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("Default"), SignGrade(150), ExecuteGrade(150)
{
    signed_ = false;
}

AForm::AForm( std::string const newName, int const gs, int const ge ) : name(newName), SignGrade(gs), ExecuteGrade(ge)
{
    signed_ = false;
    if (gs < 1 || ge < 1)
        throw GradeTooHighException();
    else if (gs > 150 || ge > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &  old ) : name(old.name), SignGrade(old.SignGrade), ExecuteGrade(old.ExecuteGrade)
{
    signed_ = old.signed_;
}

AForm& AForm::operator=( const AForm & old )
{
    signed_ = old.signed_;
    return *this;
}

int AForm::getExecuteGrade() const
{
    return ExecuteGrade;
}

int AForm::getSignGrade() const
{
    return SignGrade;
}

const std::string AForm::getName() const
{
    return name;
}

bool AForm::is_signed() const
{
    return signed_;
}

void AForm::beSigned(Bureaucrat& bureacrat)
{
    if (signed_)
        throw FormAlreadySignedException();
    if (bureacrat.getGrade() > this->getSignGrade())
        throw GradeTooLowException();
    signed_ = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade Too High !");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Grade Too Low !");
}

const char *AForm::FormAlreadySignedException::what() const throw()
{
    return "Form Already Signed";
}

const char *AForm::FormNotSigned::what() const throw()
{
    return ("Form Not Signed !");
}

std::ostream& operator<<(std::ostream& out, AForm& Aform)
{
    out << "the form \"" << Aform.getName() << "\" requires GradeToSign [ " << Aform.getSignGrade() << " ] and GradeToExecute [ " << Aform.getExecuteGrade() << " ] is ";
    if (Aform.is_signed())
        std::cout << "[✅ SIGNED]";
    else
        std::cout << "[❌ NOT SIGNED]";
    return out;
}

AForm::~AForm(){}
