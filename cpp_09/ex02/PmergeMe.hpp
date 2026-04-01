#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <cctype>
#include <cstdlib>
#include <cerrno>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <deque>


struct Element
{
	unsigned int value;
	std::vector<Element> losers;
};

class PmergeMe
{
	private:
		std::vector<Element> vec;
		std::deque<Element> deq;
		void pree(std::vector<Element> vec);
		void printAfter(std::vector<Element>, clock_t);
		//******************************** PARSE **********************************//
		unsigned int parseNumber(std::string in);
		void TrimStr(std::string& str);
		//******************************** ALGO VEC *******************************//
		std::vector<Element> fordJohnsonVEC(std::vector<Element> elements);
		void pairingVEC(std::vector<Element>& winners, std::vector<Element> oldPairs);
		std::vector<int> generatejacobOrderVEC(size_t pendSize);
		size_t jacobVEC(size_t nb);
		void BinaryInsertionVEC(std::vector<int>, std::vector<Element>, std::vector<Element>&);
		void insertloserVEC(Element, std::vector<Element>&, int, int);
		//******************************** ALGO DEQ *******************************//
		std::deque<Element> fordJohnsonDEQ(std::deque<Element> elements);
		void pairingDEQ(std::deque<Element>& winners, std::deque<Element> oldPairs);
		std::deque<int> generatejacobOrderDEQ(size_t pendSize);
		size_t jacobDEQ(size_t nb);
		void BinaryInsertionDEQ(std::deque<int>, std::deque<Element>, std::deque<Element>&);
		void insertloserDEQ(Element, std::deque<Element>&, int, int);

		//**************************** ORTHODOX ***********************************//
		PmergeMe();
		PmergeMe(const PmergeMe& old);
		PmergeMe& operator=(const PmergeMe& old);
	public:
		PmergeMe(char **av);
		void sort();
		~PmergeMe();
};