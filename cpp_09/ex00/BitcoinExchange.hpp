#pragma once

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>
#include <utility>

class BitcoinExchange
{
	std::map<std::string, double> dataBase;
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& old);
	BitcoinExchange& operator=(const BitcoinExchange& old);
	BitcoinExchange(const char* filename);
	void build();
	~BitcoinExchange();
private:
	std::ifstream input;
	void set_dataBase();
	std::string extractDate(std::istringstream &linestream);
	double extractValue(std::string line);
	bool is_leap(int year);

	typedef std::map<std::string, double>::iterator mapIt;
};
