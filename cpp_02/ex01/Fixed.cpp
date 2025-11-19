#include "Fixed.hpp"
const int Fixed::fractional = 8;

Fixed::Fixed(const int a)
{
	std::cout << "Int constructor called" << std::endl;
	fixed = a * pow(2, fractional);
}

Fixed::Fixed(const float a)
{
	std::cout << "Float constructor called" << std::endl;
	fixed = roundf(a * pow(2, fractional));
}

float Fixed::toFloat( void ) const
{
	return fixed / pow(2, fractional);
}

int Fixed::toInt( void ) const
{
	return fixed / pow(2, fractional);
}

std::ostream &operator<<(std::ostream &out, const Fixed &myObject)
{
	out << myObject.toFloat();
	return out;
}

Fixed::Fixed()
{
	fixed = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &old)
{
	this->fixed = old.fixed;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &old)
{
	this->fixed = old.fixed;
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return fixed;
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	fixed = raw;
}
