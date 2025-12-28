#include "Intern.hpp"


Intern::Intern()
{
}

Intern::Intern( const Intern & old )
{
    (void)old;
}

Intern& Intern::operator=( const Intern & old )
{
    (void)old;
    return *this;
}

AForm* Intern::makeForm( const std::string& name, const std::string& target )
{
    AForm* (Intern::*caller[3])(const std::string& );
    caller[0] = &Intern::shruberry;
    caller[1] = &Intern::robotomise;
    caller[2] = &Intern::pardon;

    std::string levels[3] = {"shruberry creation", "robotomy request", "presidential pardon"};
    for (int i = 0; i < 3; i++)
    {
        if (name == levels[i])
        {
            std::cout << "Intern creates " << name << std::endl;
            return (this->*caller[i])(target);
        }
    }
    std::cerr << "Form name not recognized: " << name << std::endl;
    return NULL;
}

AForm* Intern::shruberry( const std::string& target )
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::robotomise( const std::string& target )
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::pardon( const std::string& target )
{
    return new PresidentialPardonForm(target);
}

Intern::~Intern(){}
