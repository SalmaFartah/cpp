#pragma once
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
private:
	AForm *robotomise( const std::string& target );
	AForm *shruberry( const std::string& target );
	AForm *pardon( const std::string& target );

public:
	Intern();
	Intern( const Intern & old );
	Intern& operator=( const Intern & old );
	AForm* makeForm( const std::string& name, const std::string& target );
	~Intern();
};
