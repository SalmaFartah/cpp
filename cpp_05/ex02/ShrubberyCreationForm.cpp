#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreation", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string & newTarget ) : AForm("ShrubberyCreationForm", 145, 137)
{
    target = newTarget;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & old ) : AForm("ShrubberyCreationForm", 145, 137)
{
    target = old.target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm & old)
{
    AForm::operator=(old);
    target = old.target;
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (!is_signed())
        throw FormNotSigned();
    if (executor.getGrade() > this->getGradeExecute())
        throw GradeTooLowException();
    std::ofstream f((target + "_shrubbery").c_str());
    if (!f.is_open())
    {
        std::cerr << "permission denied" << std::endl;
    }
    std::string tree =  "       _-_\n"
                        "    /~~   ~~\\\n"
                        " /~~         ~~\\\n"
                        "{               }\n"
                        " \\  _-     -_  /\n"
                        "   ~  \\\\ //  ~\n"
                        "_- -   | | _- _\n"
                        "  _ -  | |   -_\n"
                        "      // \\\\\n";
    f << tree;
}

const char *ShrubberyCreationForm::FormNotSigned::what() const throw()
{
    return "Form Not Signed !";
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}