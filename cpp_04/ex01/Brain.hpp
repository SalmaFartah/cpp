#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
private:
	std::string ideas[100];
public:
	Brain();
	Brain( const Brain& old);
	Brain& operator=( const Brain& old);
	~Brain();
};

#endif