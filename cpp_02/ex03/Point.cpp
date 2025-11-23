#include "Point.hpp"

Point::Point() : x(), y(){}

Point::Point(const float& x1, const float& y1) : x(x1), y(y1){}

Point::Point(Point& old) : x(old.x){}

Point& Point::operator=(const Point& old)
{
    (void)old;
    return *this;
}

const Fixed& Point::X() const { return x; }
const Fixed& Point::Y() const { return y; }

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    a.X() + a.Y();
}

Point::~Point(){}
