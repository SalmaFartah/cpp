#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("Default"), GradeSign(150), GradeExecute(150)
{
    signed_ = false;
}

AForm::AForm( std::string const newName, int const gs, int const ge ) : name(newName), GradeSign(gs), GradeExecute(ge)
{
    signed_ = false;
    if (gs < 1 || ge < 1)
        throw GradeTooHighException();
    else if (gs > 150 || ge > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &  old ) : name(old.name), GradeSign(old.GradeSign), GradeExecute(old.GradeExecute)
{
    signed_ = old.signed_;
}

AForm& AForm::operator=( const AForm & old )
{
    signed_ = old.signed_;
    return *this;
}

int AForm::getGradeExecute() const
{
    return GradeExecute;
}

int AForm::getGradeSign() const
{
    return GradeSign;
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
    if (bureacrat.getGrade() > this->getGradeSign())
        throw GradeTooLowException();
    else
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
    return ("Form Already Signed");
}

std::ostream& operator<<(std::ostream& out, AForm& Aform)
{
    out << "the form \"" << Aform.getName() << "\" requires GradeToSign [ " << Aform.getGradeSign() << " ] and GradeToExecute [ " << Aform.getGradeExecute() << " ] is ";
    if (Aform.is_signed())
        std::cout << "[✅ SIGNED]";
    else
        std::cout << "[❌ NOT SIGNED]";
    return out;
}

AForm::~AForm(){}
