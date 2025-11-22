#include "Point.hpp"

Point::Point() : x(), y(){}

Point::Point(const float& x1, const float& y1) : x(x1), y(y1){}

Point::Point(Point& old) : x(old.x), y(old.y){}

// Point& Point::operator=(const Point& old)
// {
    
//     return *this;
// }

const Fixed Point::get_x() const { return x; }
const Fixed Point::get_y() const { return y; }

Fixed area( Point const a, Point const b, Point const c )
{
    
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{

}

Point::~Point(){}
