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
	Fixed(const int a);
	Fixed(const float a);
	float toFloat( void ) const;
	int toInt( void ) const;
	//---ORTHODOX CANONICAL FORM---//
	Fixed();
	Fixed(Fixed &old);
	Fixed &operator=(Fixed &old);
	~Fixed();
};

#endif
