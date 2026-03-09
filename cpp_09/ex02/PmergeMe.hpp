#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <cctype>

class PmergeMe
{
private:
	std::vector<int> vec;
	int odd;

	//********************* ALGO *********************//
	std::vector<int> fordJohnsonVec(std::vector<int> inp);
	unsigned int parseNumber(std::string in);
	void TrimStr(std::string& str);

	void pairing(std::vector<int>& sequance);
	void group(std::vector<int> vect, std::vector<int>&, std::vector<int>&);

	//****************** ORTHODOX ******************//
	PmergeMe();
	PmergeMe(const PmergeMe& old);
	PmergeMe& operator=(const PmergeMe& old);
public:
	PmergeMe(char **av);
	void sort();
	void printVec(std::vector<int>);
	~PmergeMe();

};
