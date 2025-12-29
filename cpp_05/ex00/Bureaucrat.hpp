#pragma once
#include <iostream>
#include <string>

class Bureaucrat
{
private:
	const std::string name;
	int grade;
public:
	Bureaucrat();
	Bureaucrat( const std::string newName, int newGrade );
	Bureaucrat( const Bureaucrat& old );
	Bureaucrat& operator=( const Bureaucrat& old );

	const std::string& getName() const;
	int getGrade() const;

	void incrementGrade();
	void decrementGrade();

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
