#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange( const BitcoinExchange& old)
{
	*this = old;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& old)
{
	this->dataBase = old.dataBase;
	return *this;
}

BitcoinExchange::BitcoinExchange(const char* filename): input(filename)
{
	if (!input)
		throw std::runtime_error("Error: could not open file.");
}

void BitcoinExchange::set_dataBase()
{
	std::ifstream file("data.csv");
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::stringstream linestream(line);
		std::string key;
		std::getline(linestream, key, ',');
		double value;
		linestream >> value;
		dataBase[key] = value;
	}
}

double BitcoinExchange::extractValue(std::string line)
{
	char *p = NULL;
	double value = strtod(line.c_str(), &p);
	if (line.empty() || line.find_first_not_of(" ") != 1 || *p)
		throw std::runtime_error("Error: invalid value.");

	if (value < 0)
		throw std::runtime_error("Error: not a positive number.");
	if (value > 1000)
		throw std::runtime_error("Error: too large a number.");
	return value;
}

bool BitcoinExchange::is_leap(int year)
{
	if ((!(year % 4) && year % 100) || !(year % 400))
		return true;
	return false;
}

std::string BitcoinExchange::extractDate(std::istringstream &linestream)
{
	std::string date;
	struct tm tim;
	if (!std::getline(linestream, date, '|') || date.length() != 11)
		throw std::runtime_error("Error: bad input => " + date);

	char *cur = strptime(date.c_str(), "%Y-%m-%d", &tim);
	if (!cur || *cur != 32 || cur[1] || tim.tm_year < 0 || tim.tm_mday < 1)
		throw std::runtime_error("Error: bad input => " + date);

	int month = tim.tm_mon + 1;
	if ((month == 4 || month == 6 || month == 9 || month == 11) && tim.tm_mday == 31)
		throw std::runtime_error("Error: bad input => " + date);

	if (!is_leap(tim.tm_year + 1900) && month == 2 && tim.tm_mday > 28)
		throw std::runtime_error("Error: bad input => " + date);

	date.erase(date.find(' '));
	return date;
}

void BitcoinExchange::build()
{
	std::string fstline;
	if (!std::getline(input, fstline) || fstline != "date | value")
		throw std::runtime_error("Error: invalid head.");

	set_dataBase();
	std::string line;
	while (std::getline(input, line))
	{
		std::istringstream linestream(line);
		try
		{
			std::string date = extractDate(linestream);
			double value = extractValue(line.substr(linestream.tellg()));
			mapIt it = dataBase.lower_bound(date);
			if (it == dataBase.begin() && !dataBase.count(date))
				throw std::runtime_error("Error: date not found => " + date);
			if (!dataBase.count(date))
				it--;
			std::cout << date << " => " << value << " = " << value * it->second << std::endl;
		}
		catch (std::exception& s)
		{
			std::cerr << s.what() << std::endl;
		}
	}
}

BitcoinExchange::~BitcoinExchange(){}
