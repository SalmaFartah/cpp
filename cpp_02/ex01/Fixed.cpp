#include "Fixed.hpp"
const int Fixed::fractional = 8;

Fixed::Fixed(const int a)
{
	fixed = a * std::pow(2, fractional);
}

Fixed::Fixed(const float a)
{
	fixed = a * std::pow(2, fractional);
}

float Fixed::toFloat( void ) const
{
	return fixed / std::pow(2, fractional);
}

int Fixed::toInt( void ) const
{
	return fixed / std::pow(2, fractional);
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

Fixed::Fixed(Fixed &old)
{
	this->fixed = old.fixed;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(Fixed &old)
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
