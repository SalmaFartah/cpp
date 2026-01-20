#include "Span.hpp"
#include <list>

int main()
{
	{
		try
		{
			std::cout << "TEST 1: Adding 4 numbers to Span with maxlength 3:\n";
			Span sp(3);
			sp.addNumber(36);
			sp.addNumber(42);
			sp.addNumber(18);
			sp.addNumber(9);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::cout << "\nTEST 2: Using a large list to fill Span:\n";
		try
		{
			std::list<int> lst;
			for (size_t i = 0; i < 2500; i++)
				lst.push_back(42);
			for (size_t i = 2500; i < 5000; i++)
				lst.push_back(7);
			for (size_t i = 5000; i < 7500; i++)
				lst.push_back(16);
			for (size_t i = 7500; i < 10000; i++)
				lst.push_back(0);

			Span sp(10000);
			sp.addMultiNumbers(lst.begin(), lst.end());
			std::cout << "the sortest distance in my span is: " << sp.shortestSpan() << std::endl;
			std::cout << "the longest distance in my span is: " << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::cout << "\nTEST 3: Adding numbers from a vector to a small Span:\n";
		try
		{
			std::vector<int> vect;
			vect.push_back(87);
			vect.push_back(34);
			vect.push_back(10);
			vect.push_back(56);

			Span sp(1);
			sp.addMultiNumbers(vect.begin(), vect.end());
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	
}
