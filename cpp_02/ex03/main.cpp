#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main( void )
{
    // Fixed a;
    // Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    // std::cout << a << std::endl;
    // std::cout << ++a << std::endl;
    // std::cout << a << std::endl;
    // std::cout << a++ << std::endl;
    // std::cout << a << std::endl;
    // std::cout << b << std::endl;
    // std::cout << Fixed::max( a, b ) << std::endl;
    float x = 0.4;
    float y = 3.4;
    Point original(x, y);
    Point b(original);
    return 0;
}
