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

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed TriangleArea = area(a, b, c);
    Fixed Area1 = area(a, b, point);
    Fixed Area2 = area(a, c, point);
    Fixed Area3 = area(b, c, point);

    if (TriangleArea != 0 && Area1 != 0 && Area2 != 0 && Area3 != 0 \
    && Area1 + Area2 + Area3 == TriangleArea)
        return true;    
    return false;
}
