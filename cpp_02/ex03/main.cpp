#include "Fixed.hpp"
#include "Point.hpp"


int main( void )
{
    Point a(1.0f, 0.0f);
    Point b(4.0f, 0.0f);
    Point c(2.0f, 4.0f);
    Point p(2.0f, 1.001f);
    if (bsp(a, b, c, p ))
        std::cout << "true\n";
    else
        std::cout << "false\n";
    return 0;
}
