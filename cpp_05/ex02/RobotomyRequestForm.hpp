#pragma once 
#include <string>
#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
private:
	std::string target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm( const std::string &newTarget );
	RobotomyRequestForm( const RobotomyRequestForm & old );
	RobotomyRequestForm & operator=( const RobotomyRequestForm & old );

	void execute(Bureaucrat const & executor) const;
	~RobotomyRequestForm();
};
