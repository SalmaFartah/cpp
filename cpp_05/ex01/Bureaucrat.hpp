#pragma once
#include <iostream>
#include <string>
class Form;

class Bureaucrat
{
private:
	std::string const name;
	int grade;
public:
	Bureaucrat();
	Bureaucrat( std::string const newName, int newGrade );
	Bureaucrat( const Bureaucrat& old );
	Bureaucrat& operator=( const Bureaucrat& old );

	std::string const getName() const;
	int getGrade() const;

	void incrementGrade();
	void decrementGrade();

	void signForm(Form &MyForm);

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
