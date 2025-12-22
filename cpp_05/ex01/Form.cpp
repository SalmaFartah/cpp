#include "Form.hpp"


Form::Form() : name("Default"), GradeSign(150), GradeExecute(150)
{
	sign = false;
}

Form::Form( std::string const newName, int const gs, int const ge ) : name(newName), GradeSign(gs), GradeExecute(ge)
{
	sign = false;
	if (gs < 1 || ge < 1)
		throw GradeTooHighException();
	else if (gs > 150 || ge > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &  old ) : name(old.name), GradeSign(old.GradeSign), GradeExecute(old.GradeExecute)
{
	sign = old.sign;
}

Form& Form::operator=( const Form & old )
{
	sign = old.sign;
	return *this;
}

int Form::getGradeExecute() const
{
	return GradeExecute;
}

int Form::getGradeSign() const
{
	return GradeSign;
}

const std::string Form::getName() const
{
	return name;
}

bool Form::getStatus() const
{
	return sign;
}

void Form::beSigned(Bureaucrat& obj)
{
	if (obj.getGrade() <= this->getGradeSign())
		sign = true;
	else
		throw GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade Too High !");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low !");
}

std::ostream& operator<<(std::ostream& out, Form& obj)
{
	out << "the Form \"" << obj.getName() << "\" has GradeToSign [ " << obj.getGradeSign() << " ] and GradeToExecute [ " << obj.getGradeExecute() << " ] is ";
	if (obj.getStatus())
		std::cout << "[✅ SIGNED]" << std::endl;
	else
		std::cout << "[❌ NOT SIGNED]" << std::endl;
	return out;
}

Form::~Form(){}
