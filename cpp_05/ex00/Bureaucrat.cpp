#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name( "unknown" )
{
	grade = 150;
}

Bureaucrat::Bureaucrat( std::string const newName, int newGrade ) : name(newName)
{
	if (newGrade < 1)
		throw GradeTooHighException();
	else if (newGrade > 150)
		throw GradeTooLowException();
	grade = newGrade;
}

Bureaucrat::Bureaucrat( const Bureaucrat& old) : name( old.name )
{
	grade = old.grade;
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& old )
{
	grade = old.grade;
	return *this;
}

const std::string& Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade;
}

const char *Bureaucrat::GradeTooHighException::what()  const throw()
{
	return "Grade Too High !";
}

const char *Bureaucrat::GradeTooLowException::what()  const throw()
{
	return "Grade Too Low !";
}

void Bureaucrat::incrementGrade()
{
	if (grade - 1 < 1)
		throw GradeTooHighException();
	grade--;	
}

void Bureaucrat::decrementGrade()
{
	if (grade + 1 > 150)
		throw GradeTooLowException();
	grade++;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj)
{
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return out;
}

Bureaucrat::~Bureaucrat(){}
