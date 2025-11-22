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
	Point(Point& old);
	const Fixed get_x() const ;
	const Fixed get_y() const ;
	// Point& operator=(const Point& old);
	Point();
	~Point();
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif