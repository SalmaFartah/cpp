#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name( "default" )
{
    grade = 1;
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

std::string const Bureaucrat::getName() const
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

void Bureaucrat::grade_increment()
{
    if (grade - 1 < 1)
        throw GradeTooHighException();
    grade--;	
}

void Bureaucrat::grade_decrement()
{
    if (grade + 1 > 150)
        throw GradeTooLowException();
    grade++;
}

void Bureaucrat::signForm(Form & MyForm)
{
    try
    {
        MyForm.beSigned(*this);
        std::cout << name << " signed " << MyForm.getName() << std::endl;
    }
    catch (std::exception& s)
    {
        std::cerr << name << " couldn\'t sign " << MyForm.getName() << " because " << s.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj)
{
    out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
    return out;
}

Bureaucrat::~Bureaucrat(){}
