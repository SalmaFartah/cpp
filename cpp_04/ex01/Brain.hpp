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
	Brain(Brain& old);
	Brain& operator=(Brain& old);
	void setIdeas(std::string str);
	void showIdeas();
	~Brain();
};

#endif