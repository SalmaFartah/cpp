#pragma once
#include <iostream>
#include <string>
class AForm;

class Bureaucrat
{
private:
	const std::string name;
	int grade;
public:
	Bureaucrat();
	Bureaucrat( std::string const newName, int newGrade );
	Bureaucrat( const Bureaucrat& old );
	Bureaucrat& operator=( const Bureaucrat& old );

	const std::string& getName() const;
	int getGrade() const;

	void incrementGrade();
	void decrementGrade();

	void signForm(AForm &MyForm);
	void executeForm(AForm const & form) const;

	/***************** NESTED CLASSES *****************/
	class GradeTooHighException : public std::exception
	{
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		const char *what() const throw();
	};

	~Bureaucrat();
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj);
