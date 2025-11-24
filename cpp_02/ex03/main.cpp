#include "Fixed.hpp"
#include "Point.hpp"



int main()
{
    Point a(-1.7f, -2.3f);
    Point b(4.5f, 2.6f);
    Point c(7.3f, -1.6f);
	Point inside(3.0f, 0.0f);
	Point outside(-1.8f, 3.6f);
	Point onEdge(1.4f, 0.15f);



	if (bsp(a,b,c,onEdge))
		return std::cout << "Point is inside the triangle\n", 0;
	return std::cout << "Point is outside the triangle\n", 1;	
}
