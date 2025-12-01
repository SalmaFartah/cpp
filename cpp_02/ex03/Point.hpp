#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	const Fixed x;
	const Fixed y;
public:
	Point(const float x, const float y);
	const Fixed& X() const ;
	const Fixed& Y() const ;

	//------CANNONICAL FORM-----------
	Point();
	Point(const Point& old);
	Point& operator=(const Point& old);
	~Point();
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
