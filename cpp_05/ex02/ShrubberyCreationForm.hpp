#pragma once
#include <string>
#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm( const std::string & newTarget );
		ShrubberyCreationForm(const ShrubberyCreationForm & old);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm & old);

		void execute(Bureaucrat const & executor) const;
		~ShrubberyCreationForm();
};
