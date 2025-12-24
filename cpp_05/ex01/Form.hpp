#pragma once
#include <string>
#include <iostream>

class Bureaucrat;

class Form
{
private:
	std::string const name;
	bool signed_;
	int const GradeSign;
	int const GradeExecute;
public:
	Form();
	Form(std::string const newName, int const gs, int const ge);
	Form(const Form & old);
	Form& operator=(const Form & old);

	int getGradeSign() const;
	int getGradeExecute() const;
	const std::string getName() const;
	bool getStatus() const;

	void beSigned(Bureaucrat & obj);

	class GradeTooHighException : public std::exception
	{
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		const char *what() const throw();
	};

	~Form();
};

std::ostream& operator<<(std::ostream& out, Form& obj);