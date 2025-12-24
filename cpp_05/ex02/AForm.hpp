#pragma once
#include <string>
#include <iostream>

class Bureaucrat;

class AForm
{
private:
	std::string const name;
	bool signed_;
	int const GradeSign;
	int const GradeExecute;
public:
	AForm();
	AForm(std::string const newName, int const gs, int const ge);
	AForm(const AForm & old);
	AForm& operator=(const AForm & old);

	int getGradeSign() const;
	int getGradeExecute() const;
	const std::string getName() const;
	bool is_signed() const;

	void beSigned(Bureaucrat & obj);

	virtual void execute(Bureaucrat const & executor) const = 0;

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
	~AForm();
};

std::ostream& operator<<(std::ostream& out, AForm& obj);