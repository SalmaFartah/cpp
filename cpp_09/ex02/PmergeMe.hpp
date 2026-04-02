#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <cctype>
#include <cstdlib>
#include <cerrno>
#include <algorithm>
#include <ctime>
#include <iomanip>

struct ElementD
{
	unsigned int value;
	std::deque<ElementD> losers;
};

struct ElementV
{
	unsigned int value;
	std::vector<ElementV> losers;
};


class PmergeMe
{
	private:
		std::vector<ElementV> vec;
		std::deque<ElementD> deq;
		void pree(std::vector<ElementV> vec);
		void printAfter(std::vector<ElementV>, clock_t);
		//******************************** PARSE **********************************//
		unsigned int parseNumber(std::string in);
		void TrimStr(std::string& str);
		//******************************** ALGO VEC *******************************//
		std::vector<ElementV> fordJohnsonVEC(std::vector<ElementV> elements);
		void pairingVEC(std::vector<ElementV>& winners, std::vector<ElementV> oldPairs);
		std::vector<int> generatejacobOrderVEC(size_t pendSize);
		size_t jacobVEC(size_t nb);
		void BinaryInsertionVEC(std::vector<int>, std::vector<ElementV>, std::vector<ElementV>&);
		void insertloserVEC(ElementV, std::vector<ElementV>&, int, int);
		//******************************** ALGO DEQ *******************************//
		std::deque<ElementD> fordJohnsonDEQ(std::deque<ElementD> elements);
		void pairingDEQ(std::deque<ElementD>& winners, std::deque<ElementD> oldPairs);
		std::deque<int> generatejacobOrderDEQ(size_t pendSize);
		size_t jacobDEQ(size_t nb);
		void BinaryInsertionDEQ(std::deque<int>, std::deque<ElementD>, std::deque<ElementD>&);
		void insertloserDEQ(ElementD, std::deque<ElementD>&, int, int);

		//**************************** ORTHODOX ***********************************//
		PmergeMe();
		PmergeMe(const PmergeMe& old);
		PmergeMe& operator=(const PmergeMe& old);
	public:
		PmergeMe(char **av);
		void sort();
		~PmergeMe();
};