#pragma once
#include <string>
#include <iostream>

class Bureaucrat;

class AForm
{
private:
	std::string const name;
	bool signed_;
	int const SignGrade;
	int const ExecuteGrade;
public:
	AForm();
	AForm(std::string const newName, int const gs, int const ge);
	AForm(const AForm & old);
	AForm& operator=(const AForm & old);

	/******************* GETERS *********************/
	int getSignGrade() const;
	int getExecuteGrade() const;
	const std::string getName() const;
	bool is_signed() const;
	/************************************************/

	void beSigned(Bureaucrat & obj);
	virtual void execute(Bureaucrat const & executor) const = 0;

	/******************* EXCEPTION CLASSES *******************/
	class GradeTooHighException : public std::exception
	{
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		const char *what() const throw();
	};
	class FormAlreadySignedException : public std::exception
	{
		const char *what() const throw();
	};
	class FormNotSigned : public std::exception
	{
		const char *what() const throw();
	};
	/**********************************************************/

	virtual ~AForm();
};

std::ostream& operator<<(std::ostream& out, AForm& obj);