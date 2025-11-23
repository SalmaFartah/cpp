#include "Fixed.hpp"
const int Fixed::fractional = 8;

Fixed::Fixed()
{
	fixed = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &old)
{
	this->fixed = old.fixed;
	std::cout << "Copy constructor called" << std::endl;
}

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
	return fixed / std::pow(2, fractional);
}

int Fixed::toInt( void ) const
{
	return fixed / std::pow(2, fractional);
}

std::ostream &operator<<(std::ostream &out, const Fixed &myObject)
{
	out << myObject.toFloat();
	return out;
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

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}


bool Fixed::operator<( const Fixed &obj2 ) const
{
	return this->toFloat() < obj2.toFloat();
}

bool Fixed::operator>( const Fixed &obj2 ) const
{
	return this->toFloat() > obj2.toFloat();
}

bool Fixed::operator<=( const Fixed &obj2 ) const
{
	return this->toFloat() <= obj2.toFloat();
}

bool Fixed::operator>=( const Fixed &obj2 ) const
{
	return this->toFloat() >= obj2.toFloat();
}

bool Fixed::operator==( const Fixed &obj2 ) const
{
	return this->toFloat() == obj2.toFloat();
}

bool Fixed::operator!=( const Fixed &obj2 ) const
{
	return this->toFloat() != obj2.toFloat();
}



Fixed Fixed::operator+( const Fixed &obj2 ) const
{
	Fixed result;
	result.fixed = (this->fixed + obj2.fixed);
	return result;
}

Fixed Fixed::operator-( const Fixed &obj2 ) const
{
	Fixed result;
	result.fixed = (this->fixed - obj2.fixed);
	return result;
}

Fixed Fixed::operator*( const Fixed &obj2 ) const
{
	Fixed result;
	result.fixed = (( this->fixed * obj2.fixed ) / std::pow(2, fractional));
	return result;
}

Fixed Fixed::operator/( const Fixed &obj2 ) const
{
	Fixed result;
	result.fixed = (( this->fixed * pow(2, fractional) ) / obj2.fixed);
	return result;
}


Fixed &Fixed::operator--()
{
	this->fixed--;
	return *this;
}

Fixed Fixed::operator--(int c)
{
	(void)c;
	Fixed result;
	result.fixed = this->fixed;
	this->fixed--;
	return result;
}

Fixed &Fixed::operator++()
{
	this->fixed++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed result;
	result.fixed = this->fixed;
	this->fixed++;
	return result;
}

Fixed& Fixed::max(Fixed &obj1, Fixed &obj2)
{
	if (obj1 > obj2)
		return obj1;
	return obj2;
}

Fixed& Fixed::min(Fixed &obj1, Fixed &obj2)
{
	if (obj1 < obj2)
		return obj1;
	return obj2;
}

const Fixed& Fixed::max(const Fixed &obj1, const Fixed &obj2)
{
	if (obj1 > obj2)
		return obj1;
	return obj2;
}

const Fixed& Fixed::min(const Fixed &obj1, const Fixed &obj2)
{
	if (obj1 < obj2)
		return obj1;
	return obj2;
}