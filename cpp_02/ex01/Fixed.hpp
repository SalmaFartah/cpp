#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int fixed;
	static const int fractional;
public:
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	//------------EX01-------------//
	Fixed(const int a);// it must store a as fixed point number with 8 bits for fractional part
	Fixed(const float a);// it must store a as fixed point number with 8 bits for fractional part
	float toFloat( void ) const;
	int toInt( void ) const;
	//---ORTHODOX CANONICAL FORM---//
	Fixed();
	Fixed(const Fixed &old);
	Fixed &operator=(const Fixed &old);
	~Fixed();
};

std::ostream &operator<<(std::ostream &out, const Fixed &myObject);

#endif
