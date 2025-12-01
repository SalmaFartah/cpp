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
	//----COMPARISON-OPERATORS----//
	bool operator<( const Fixed &obj2 ) const;
	bool operator<=( const Fixed &obj2 ) const;
	bool operator>( const Fixed &obj2 ) const;
	bool operator>=( const Fixed &obj2 ) const;
	bool operator==( const Fixed &obj2 ) const;
	bool operator!=( const Fixed &obj2 ) const;

	//-----ARITHMETIC-OPERATOR-----//
	Fixed operator+( const Fixed &obj2 ) const;
	Fixed operator-( const Fixed &obj2 ) const;
	Fixed operator*( const Fixed &obj2 ) const;
	Fixed operator/( const Fixed &obj2 ) const;

	//-----DECREMENT-OPERATORS-----//
	Fixed operator--(int);
	Fixed &operator--();

	//-----INCREMENT-OPERATORS-----//
	Fixed operator++(int);
	Fixed &operator++();

	//-----MAX-MIN-FUNCTIONS-----//
	static Fixed& max(Fixed &obj1, Fixed &obj2);
	static Fixed& min(Fixed &obj1, Fixed &obj2);
	static const Fixed& max(const Fixed &obj1, const Fixed &obj2);
	static const Fixed& min(const Fixed &obj1, const Fixed &obj2);
	//------------EX01-------------//
	Fixed(const int a);
	Fixed(const float a);
	float toFloat( void ) const;
	int toInt( void ) const;
	//----------GET-SET------------//
	int getRawBits( void ) const;
	void setRawBits( int const raw );

	//---ORTHODOX-CANONICAL-FORM---//
	Fixed();
	Fixed(const Fixed &old);
	Fixed &operator=(const Fixed &old);
	~Fixed();
};

std::ostream &operator<<(std::ostream &out, const Fixed &myObject);

#endif
