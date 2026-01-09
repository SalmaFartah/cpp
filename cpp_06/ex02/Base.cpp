#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(){}

Base * generate(void)
{
	std::srand(time(0));
	int t = std::rand() % 3;
	if (t == 0)
		return new A;
	if (t == 1)
		return new B;
	return new C;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	try 
	{
		A x = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch (std::exception & s){}

	try
	{
		B x = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	}
	catch(std::exception& e){}

	try
	{
		C x = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}
	catch(std::exception& e){}
}
