#pragma once
#include <string>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm( const std::string & newTarget );
	PresidentialPardonForm( const PresidentialPardonForm & old );
	PresidentialPardonForm& operator=( const PresidentialPardonForm & old );

	void execute(Bureaucrat const & executor) const;
	~PresidentialPardonForm();
};
