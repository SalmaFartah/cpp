#include "Harl.hpp"

Harl::Harl()
{
	caller[0] = &Harl::debug;
	caller[1] = &Harl::info;
	caller[2] = &Harl::warning;
	caller[3] = &Harl::error;

	table[0] = "DEBUG";
	table[1] = "INFO";
	table[2] = "WARNING";
	table[3] = "ERROR";
}

Harl::~Harl(){}

void Harl::debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
}

void Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn\'t put enough bacon in my burger! If you did, I wouldn\'t be asking for more!\n";
}

void Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month.\n";
}

void Harl::error()
{	
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void   Harl::complain( std::string level )
{
	int i = 0;
	while (i < 4 && level != table[i])
		i++;
	switch (i)
	{
		case 0:
			std::cout << "[ " << table[i] << " ]\n";
			(this->*caller[i])();
			std::cout << '\n';
			i++;
			/* falls through */
		case 1:
			std::cout << "[ " << table[i] << " ]\n";
			(this->*caller[i])();
			std::cout << '\n';
			i++;
			/* falls through */
		case 2:
			std::cout << "[ " << table[i] << " ]\n";
			(this->*caller[i])();
			std::cout << '\n';
			i++;
			/* falls through */
		case 3:
			std::cout << "[ " << table[i] << " ]\n";
			(this->*caller[i])();
			std::cout << '\n';
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
}
