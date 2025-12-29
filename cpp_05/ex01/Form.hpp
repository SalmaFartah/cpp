#pragma once
#include <string>
#include <iostream>

class Bureaucrat;

class Form
{
private:
	std::string const name;
	bool signed_;
	int const SignGrade;
	int const ExecuteGrade;
public:
	Form();
	Form(std::string const newName, int const gs, int const ge);
	Form(const Form & old);
	Form& operator=(const Form & old);

	/******************* GETERS *******************/
	int getSignGrade() const;
	int getExecuteGrade() const;
	const std::string getName() const;
	bool is_signed() const;
	/**********************************************/

	void beSigned(Bureaucrat & obj);

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
	/**********************************************************/

	~Form();
};

std::ostream& operator<<(std::ostream& out, Form& obj);