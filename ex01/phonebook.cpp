#include "PhoneBook.hpp"

std::string getvline(std::string prompt)
{
	std::string line;
	while (line.empty())
	{
		std::cout << prompt;
		std::getline(std::cin, line);
	}
	return line;
}

void PhoneBook::add_contact(int i)
{
	std::string line;

	line = getvline("First name: ");
	arr[i].set_first_name(line);

	line = getvline("Last name: ");
	arr[i].set_last_name(line);

	line = getvline("Nickname: ");
	arr[i].set_nickname(line);

	line = getvline("Phone number: ");
	arr[i].set_phone_number(line);

	line = getvline("Darkest secret: ");
	arr[i].set_darkest_secret(line);

	std::cout << "✅ Done !" << std::endl;
}

std::string	NormalizeStr(std::string str)
{
	std::string ret;
	int         i;

	i = 0;
	if (str.length() > 10)
	{
		while (i < 9)
		{
			ret += str[i];
			i++;
		}
		ret += '.';
		return ret;
	}
	ret = str;
	while (ret.length() < 10)
	{
		ret += " ";
	}
	return ret;
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

void PhoneBook::search(int size)
{
	std::string	firstName;
	std::string	lastName;
	std::string	nicktName;
	int			i;
	
	i = 0;
	if (size == 0)
	{
		std::cout << "phonebook empty !" << std::endl;
		return ;
	}

	std::cout << "index     |first name|last name |nickname" << std::endl;
	while (i < size)
	{
		firstName = NormalizeStr(arr[i].get_first_name());
		lastName = NormalizeStr(arr[i].get_last_name());
		nicktName = NormalizeStr(arr[i].get_nickname());
		std::cout << i << "         " << "|" << firstName \
		<< "|" << lastName << "|" << nicktName << std::endl;
		i++;
	}

	int			index;
	std::string line;

	while (1)
	{
		std::cout << "choose index > ";
		if (!std::getline(std::cin, line))
        {
            std::cout << std::endl;
            exit(0) ;
        }
		if (ifdigit(line) && (index = std::atoi(line.c_str())) >= 0 && index < size)
		{
				std::cout << "First name    : " << arr[index].get_first_name() << std::endl;
				std::cout << "Last name     : " << arr[index].get_last_name() << std::endl;
				std::cout << "Nickname      : " << arr[index].get_nickname() << std::endl;
				std::cout << "Phone number  : " << arr[index].get_phone_number() << std::endl;
				std::cout << "Darkest secret: " << arr[index].get_darkest_secret() << std::endl;
				return ;
		}
		else
			std::cout << "invalid index, try again !" << std::endl;
	}
}
