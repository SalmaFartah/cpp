#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("shrubbery creation", 145, 137){}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string & newTarget ) : AForm("shrubbery creation", 145, 137)
{
    target = newTarget;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & old ) : AForm(old)
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
    if (executor.getGrade() > this->getExecuteGrade()) // low 
        throw GradeTooLowException();

    std::ofstream outfile((target + "_shrubbery").c_str());
    if (!outfile.is_open())
    {
        std::cerr << target << "_shrubbery: permission denied" << std::endl;
        return ;
    }
    outfile <<      "       _-_\n"
                    "    /~~   ~~\\\n"
                    " /~~         ~~\\\n"
                    "{               }\n"
                    " \\  _-     -_  /\n"
                    "   ~  \\\\ //  ~\n"
                    "_- -   | | _- _\n"
                    "  _ -  | |   -_\n"
                    "      // \\\\\n";;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}