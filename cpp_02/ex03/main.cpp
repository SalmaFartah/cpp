#include "Point.hpp"


int main( void )
{
    Point a(1.5f, 1.5f);
    Point b(3.5f, 1.5f);
    Point c(2.5f, 3.5f);
    Point inSide(2.5f, 2.5f);
    // Point outSide(2.5f, 4.0f);
    // Point onEdge(2.5f, 1.5f);
    // Point onvetx(1.5f, 1.5f);

    if (bsp(a, b, c, inSide))
        return std::cout << "the point is inside the triangle" << std::endl, 0;
    return std::cout << "the point is outside the triangle" << std::endl, 1;
}
