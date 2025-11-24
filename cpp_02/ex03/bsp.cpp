#include "Point.hpp"
#include "Fixed.hpp"

Fixed& absFx(Fixed& object)
{
    object.setRawBits(abs(object.getRawBits()));
    return object;
}

Fixed area( Point const a, Point const b, Point const c )
{
    Fixed _area((a.X() * (b.Y() - c.Y())) + (b.X() * (c.Y() - a.Y())) + (c.X() * (a.Y() - b.Y())));
    _area = absFx(_area) / 2;
    return _area;
}

Fixed cross_(Point const p1, Point const p2, Point const point )
{
    return (p2.X() - p1.X()) * (point.Y() - p1.Y()) - (p2.Y() - p1.Y()) * (point.X() - p1.X());
}

bool bsp( Point const a, Point const b, Point const c, Point const point )
{
    Fixed cross1 = cross_(a, b, point);
    Fixed cross3 = cross_(b, c, point);
    Fixed cross2 = cross_(c, a, point);

    if (( cross1 > 0 && cross2 > 0 && cross3 > 0 ) || ( cross1 < 0 && cross2 < 0 && cross3 < 0 ))
        return true;    
    return false;
}
