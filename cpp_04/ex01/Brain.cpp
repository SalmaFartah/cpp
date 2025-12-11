#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain created! 🧠✨ New ideas incoming!" << std::endl;
}

Brain::Brain( const Brain& old)
{
	for (size_t i = 0; i < 100; i++)
		ideas[i] = old.ideas[i];
	
	std::cout << "Brain copied! 🧬✨ One mind becomes two!" << std::endl;
}

Brain& Brain::operator=( const Brain& old)
{
	for (size_t i = 0; i < 100; i++)
		ideas[i] = old.ideas[i];

	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destroyed! 💀✨ The ideas fade away..." << std::endl;
}
