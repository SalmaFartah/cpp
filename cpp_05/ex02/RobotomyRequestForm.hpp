#pragma once 
#include <string>
#include <AForm.hpp>

class RobotomyRequestForm : public AForm
{
private:
	std::string target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm( std::string &newTarget );
	RobotomyRequestForm( RobotomyRequestForm & const old );
	RobotomyRequestForm & operator=( RobotomyRequestForm & const old );

	void execute(Bureaucrat const & executor) const;
	~RobotomyRequestForm();
};
