#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	const Fixed x;
	const Fixed y;
public:
	Point(const float& x, const float& y);
	Point(const Point& old);
	const Fixed& X() const ;
	const Fixed& Y() const ;
	Point& operator=(const Point& old);
	Point();
	~Point();
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
Fixed area( Point const a, Point const b, Point const c );

#endif