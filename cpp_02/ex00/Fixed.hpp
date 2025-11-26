#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int fixed;
	static const int fractional;
public:
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	//---ORTHODOX CANONICAL FORM---//
	Fixed();
	Fixed(const Fixed &old);
	Fixed &operator=(const Fixed &old);
	~Fixed();
};

#endif