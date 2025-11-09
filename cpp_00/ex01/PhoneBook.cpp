#include "PhoneBook.hpp"

std::string getvline(std::string prompt)
{
	std::string line;

	while (line.empty())
	{
		std::cout << prompt;
		if (!std::getline(std::cin, line))
		{
			std::cout << std::endl;
			return line;
		}
	}
	return line;
}

bool PhoneBook::add_contact(int i)
{
	std::string line;

	line = getvline("First name: ");
	if (std::cin.eof())
		exit(0);
	arr[i].set_first_name(line);

	line = getvline("Last name: ");
	if (std::cin.eof())
		return false;
	arr[i].set_last_name(line);

	line = getvline("Nickname: ");
	if (std::cin.eof())
		return false;
	arr[i].set_nickname(line);

	line = getvline("Phone number: ");
	if (std::cin.eof())
		return false;
	arr[i].set_phone_number(line);

	line = getvline("Darkest secret: ");
	if (std::cin.eof())
		return false;
	arr[i].set_darkest_secret(line);

	std::cout << "✅ Done !" << std::endl;
	return true;
}

int ifdigit(std::string str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!std::isdigit(str[i]))
			return 0;
		i++;		
	}
	return 1;
}

std::string	NormalizeStr(std::string str)
{
	if (str.length() > 10)
		return str.replace(9, str.length() - 9, ".");

	std::ostringstream ret;
	ret << std::right << std::setw(10) << str;
	return ret.str();
}

bool PhoneBook::search(int size)
{
	std::string	firstName;
	std::string	lastName;
	std::string	nicktName;
	int			i;

	if (size == 0)
		return std::cout << "phonebook empty !" << std::endl, true;

	std::cout << std::right << std::setw(10) << "index" 
	<< "|" << std::right << std::setw(10) << "first name" 
	<< "|" << std::right << std::setw(10) << "last name" 
	<< "|" << std::right << std::setw(10) <<  "nickname" 
	<< std::endl;

	i = 0;
	while (i < size)
	{
		firstName = NormalizeStr(arr[i].get_first_name());
		lastName = NormalizeStr(arr[i].get_last_name());
		nicktName = NormalizeStr(arr[i].get_nickname());

		std::cout << std::right << std::setw(10) << i 
		<< "|" << firstName
		<< "|" << lastName 
		<< "|" << nicktName 
		<< std::endl;
		i++;
	}

	int			index;
	std::string line;

	while (1)
	{
		std::cout << "choose index > ";
		if (!std::getline(std::cin, line)) // ^D
        {
            std::cout << std::endl;
            return false;
        }
		if (!line.empty() && ifdigit(line) && (index = std::atoi(line.c_str())) >= 0 && index < size) // c_str return const char*
		{
				std::cout << "First name    : " << arr[index].get_first_name() << std::endl;
				std::cout << "Last name     : " << arr[index].get_last_name() << std::endl;
				std::cout << "Nickname      : " << arr[index].get_nickname() << std::endl;
				std::cout << "Phone number  : " << arr[index].get_phone_number() << std::endl;
				std::cout << "Darkest secret: " << arr[index].get_darkest_secret() << std::endl;
				break ;
		}
		std::cout << "invalid index, try again !" << std::endl;
	}
	return true;
}
