#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **av)
{
	for (int i = 1; av[i]; i++)
	{
		unsigned int nb = parseNumber(av[i]);
		vec.push_back(nb);
	}
}

void PmergeMe::TrimStr(std::string& str)
{
	size_t start = str.find_first_not_of(" \t\n\r\f\v");
	if (start == std::string::npos)
		throw std::runtime_error("Error: invalid input.");
	size_t end = str.find_last_not_of(" \t\n\r\f\v");
	str = str.substr(start, end - start + 1);
}

unsigned int PmergeMe::parseNumber(std::string in)
{
	if (in.empty() || in.find("0123456789 \t\r\v\n") != in.npos)
		throw std::runtime_error("Error: invalid input.");
	TrimStr(in); // remove spaces from begin and end of string
	char *end = NULL;
	long number = std::strtol(in.c_str(), &end, 10);
	if (*end || errno == ERANGE || number < 0 || number > INT_MAX)
		throw std::runtime_error("Error: invalid input.");
	return number;
}

void PmergeMe::printVec(std::vector<int> vect)
{
	for (size_t i = 0; i < vect.size(); i++)
		std::cout << vect[i] << " ";
	std::cout << "\n";
}

void PmergeMe::pairing(std::vector<int>& sequance)
{
	size_t size = sequance.size();
	if (odd)
		size = sequance.size() - 1;
	
	for (size_t i = 0; i < size; i += 2)
	{
		if (sequance[i] > sequance[i + 1])
		{
			int tmp = sequance[i];
			sequance[i] = sequance[i + 1];
			sequance[i + 1] = tmp;
		}
	}
}

void PmergeMe::group(std::vector<int> sequance, std::vector<int>& bigs, std::vector<int>& smalls)
{
	size_t size = sequance.size();
	if (odd)
		size = sequance.size() - 1;
	for (size_t i = 0; i < size; i++)
	{
		if (i % 2)
			bigs.push_back(sequance[i]);
		else
			smalls.push_back(sequance[i]);
	}
}

std::vector<int> PmergeMe::fordJohnsonVec(std::vector<int> sequance)
{
	if (sequance.size() == 1)
		return sequance;

	odd = sequance.size() % 2;
	int stragler = 0;
	pairing(sequance);
	std::vector<int> bigs, smalls;
	group(sequance, bigs, smalls);
	if (odd)
		stragler = *(sequance.rbegin());
	fordJohnsonVec(bigs);
	std::vector<int> mainChain;
	
	return sequance;
}

void PmergeMe::sort()
{
	fordJohnsonVec(vec);
}

PmergeMe::~PmergeMe(){}
