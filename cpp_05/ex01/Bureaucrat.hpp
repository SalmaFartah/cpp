#pragma once
#include <iostream>
#include <string>
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

	void grade_increment();
	void grade_decrement();

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
