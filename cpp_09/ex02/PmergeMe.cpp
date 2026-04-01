#include "PmergeMe.hpp"

//********************************************* PRINT ******************************************** */
void PmergeMe::pree(std::vector<Element> vec)
{
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i].value << " ";
	std::cout << std::endl;
}

void PmergeMe::printAfter(std::vector<Element> fin, clock_t start)
{
	clock_t end = clock();
	std::cout << "after:   ", pree(fin);
	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << fin.size() << " elements with std::vector : "
	<< (double)(end - start) / CLOCKS_PER_SEC << " seconds" << std::endl;
}

//********************************************* PARSE ******************************************** */
PmergeMe::PmergeMe(char **av)
{
	Element elemtents;
	for (int i = 1; av[i]; i++)
	{
		unsigned int nb = parseNumber(av[i]);
		elemtents.value = nb; // initlize our vector of struct element with vl and empty chain
		vec.push_back(elemtents);
		deq.push_back(elemtents);
	}
	std::cout << "before:  "; pree(vec);
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
	TrimStr(in); // remove spaces from begin and end of string
	char *end = NULL;
	long number = std::strtol(in.c_str(), &end, 10);
	if (*end || errno == ERANGE || number < 0 || number > __INT_MAX__)
		throw std::runtime_error("Error: invalid input.");
	return number;
}

//************************************** START ALGO ***************************************** */
void PmergeMe::sort()
{
	clock_t start = clock();
	if (vec.size() == 1)
	{
		printAfter(vec, start);
		return ;
	}
	std::vector<Element> sorted = fordJohnsonVEC(vec);
	printAfter(sorted, start);
	start = clock();
	std::deque<Element> sortedDeq = fordJohnsonDEQ(deq);
	std::cout << "Time to process a range of " << sortedDeq.size() << " elements with std::deque : "
	<< (double)(clock() - start) / CLOCKS_PER_SEC << " seconds" << std::endl;
}

//******************************************************************************************* */
/*                                                                                            */
/*                                         VECTOR                                             */
/*                                                                                            */
//******************************************************************************************* */

std::vector<Element> PmergeMe::fordJohnsonVEC(std::vector<Element> elements)
{
	if (elements.size() == 1)
		return elements;

	Element stragler;
	bool hasStragler = false;
	if (elements.size() % 2)
	{
		hasStragler = true;
		stragler = elements.back();
		elements.pop_back();
	}

	std::vector<Element> winners;
	pairingVEC(winners, elements); // Each winner now carries its loser in its chain!

	std::vector<Element> mainChain = fordJohnsonVEC(winners);

	std::vector<Element> pend;
	// loop thrgout mainChain and rm last loser of each one and add them to the pends
	for (size_t i = 0; i < mainChain.size(); i++) 
	{
		pend.push_back(mainChain[i].losers.back());
		mainChain[i].losers.pop_back();
	}

	mainChain.insert(mainChain.begin(), pend[0]); // FIRST INSERT in MainChain

	 // if pend has jst two element no need to do jacoborder, jst insert the remaining element
	 // the first element in inserted before as first loser 
	if (pend.size() == 2)
		insertloserVEC(pend[1], mainChain, 0, mainChain.size());
	else
	{
		std::vector<int> jacobOrder = generatejacobOrderVEC(pend.size());
		BinaryInsertionVEC(jacobOrder, pend, mainChain);
	}
	//insrt stragler
	if (hasStragler)
		insertloserVEC(stragler, mainChain, 0, mainChain.size());
	return mainChain;
}

void PmergeMe::pairingVEC(std::vector<Element>& winners, std::vector<Element> elements) // 
{
	for (size_t i = 0; i < elements.size(); i += 2)
	{
		if (elements[i].value > elements[i + 1].value)
		{
			elements[i].losers.push_back(elements[i + 1]);
			winners.push_back(elements[i]);
		}
		else	
		{
			elements[i + 1].losers.push_back(elements[i]);
			winners.push_back(elements[i + 1]);
		}
	}
}

//************************************** JACOB ORDER ***************************************** */
std::vector<int> PmergeMe::generatejacobOrderVEC(size_t pendSize)
{
	std::vector<int> jacobSeq;
	std::vector<int> fillOrder;
	std::vector<int> previous;

	//******************** GENERATE JACOB SEQUENCE ********************//
	size_t j;
	for (j = 0; jacobVEC(j) <= pendSize ; j++) // pen[4]
	{
		if (jacobVEC(j) > 1)
		{
			jacobSeq.push_back(jacobVEC(j)); // jacob filled
			previous.push_back(jacobVEC(j - 1));  // previous jacob // ghanhtajoh f order
		}	
	}
	
	//****************** EXTRACT ORDER FROM JACOB SEQ *****************//
	for (size_t i = 0; i < jacobSeq.size(); i++)
	{
		for(int n = jacobSeq[i]; n > previous[i]; n--)
			fillOrder.push_back(n - 1); // For n = 3 (prev = 1): insert b3, b2 → 2 elements
	}
	
	
	//************************ LEFT IN REVERSE ************************//
	for (size_t end = pendSize; end > jacobVEC(j - 1); end--) // check if leftover
		fillOrder.push_back(end - 1);
	return fillOrder;
}

size_t PmergeMe::jacobVEC(size_t nb)
{
	if (nb == 0)
		return 0;
	if (nb == 1)
		return 1;
	return (jacobVEC(nb-1) + (2 * jacobVEC(nb - 2)));
}
//************************************* BINARY SEARCH ****************************************** */

void PmergeMe::insertloserVEC(Element loser, std::vector<Element>& mainChain, int start, int end)
{
	int range = end - start;
	if (range == 0)
	{
        mainChain.insert(mainChain.begin() + start, loser);
		return ;
	}

    int mid = range / 2;

    if (loser.value < mainChain[mid + start].value)
        insertloserVEC(loser, mainChain, start, mid + start);
    else
        insertloserVEC(loser, mainChain, mid + start + 1, end);
}

void PmergeMe::BinaryInsertionVEC(std::vector<int> jacobOrder, std::vector<Element> pend, std::vector<Element>& mainChain)
{
	std::vector<Element> orderedPend;
	std::vector<int> winPos;

	// loop through jacob vector and take the elements with its winner position in mainChain
	for (size_t i = 0; i < jacobOrder.size(); i++)
	{
		int idx = jacobOrder[i];
		orderedPend.push_back(pend[idx]); // take ordered elements from pend
		winPos.push_back(idx + 1); // here we track winner position for each pend 
	}

	for (size_t i = 0; i < orderedPend.size(); i++)
	{
		insertloserVEC(orderedPend[i], mainChain, 0, winPos[i]);
		for (size_t j = 0; j < winPos.size(); j++)
			winPos[j]++;
	}
}

//******************************************************************************************* */
/*                                                                                            */
/*                                         DEQUE                                              */
/*                                                                                            */
//******************************************************************************************* */

std::deque<Element> PmergeMe::fordJohnsonDEQ(std::deque<Element> elements)
{
	if (elements.size() == 1)
		return elements;

	Element stragler;
	bool hasStragler = false;
	if (elements.size() % 2)
	{
		hasStragler = true;
		stragler = elements.back();
		elements.pop_back();
	}

	std::deque<Element> winners;
	pairingDEQ(winners, elements); // Each winner now carries its loser in its chain!

	std::deque<Element> mainChain = fordJohnsonDEQ(winners);

	std::deque<Element> pend;
	// loop thrgout mainChain and rm last loser of each one and add them to the pends
	for (size_t i = 0; i < mainChain.size(); i++)
	{
		pend.push_back(mainChain[i].losers.back());
		mainChain[i].losers.pop_back();
	}

	mainChain.push_front(pend[0]); // FIRST INSERT in MainChain

	 // if pend has jst two element no need to do jacoborder, jst insert the remaining element
	 // the first element in inserted before as first loser 
	if (pend.size() == 2)
		insertloserDEQ(pend[1], mainChain, 0, mainChain.size());
	else
	{
		std::deque<int> jacobOrder = generatejacobOrderDEQ(pend.size());
		BinaryInsertionDEQ(jacobOrder, pend, mainChain);
	}
	//insrt stragler
	if (hasStragler)
		insertloserDEQ(stragler, mainChain, 0, mainChain.size());
	return mainChain;
}

void PmergeMe::pairingDEQ(std::deque<Element>& winners, std::deque<Element> elements)
{
	for (size_t i = 0; i < elements.size(); i += 2)
	{
		if (elements[i].value > elements[i + 1].value)
		{
			elements[i].losers.push_back(elements[i + 1]);
			winners.push_back(elements[i]);
		}
		else	
		{
			elements[i + 1].losers.push_back(elements[i]);
			winners.push_back(elements[i + 1]);
		}
	}
}

//************************************** JACOB ORDER ******************************************* */
std::deque<int> PmergeMe::generatejacobOrderDEQ(size_t pendSize)
{
	std::deque<int> jacobSeq;
	std::deque<int> fillOrder;
	std::deque<int> previous;

	//******************** GENERATE JACOB SEQUENCE ********************//
	size_t j;
	for (j = 0; jacobDEQ(j) <= pendSize ; j++)
	{
		if (jacobDEQ(j) > 1)
		{
			jacobSeq.push_back(jacobDEQ(j)); // jacob filled
			previous.push_back(jacobDEQ(j - 1));  // previous jacob // ghanhtajoh f order
		}	
	}
	
	//****************** EXTRACT ORDER FROM JACOB SEQ *****************//
	for (size_t i = 0; i < jacobSeq.size(); i++)
	{
		for(int n = jacobSeq[i]; n > previous[i]; n--)
			fillOrder.push_back(n - 1); // For n = 3 (prev = 1): insert b3, b2 → 2 elements
	}
	
	
	//************************ LEFT IN REVERSE ************************//
	for (size_t end = pendSize; end > jacobDEQ(j - 1); end--) // check if leftover
		fillOrder.push_back(end - 1);
	return fillOrder;
}

size_t PmergeMe::jacobDEQ(size_t nb)
{
	if (nb == 0)
		return 0;
	if (nb == 1)
		return 1;
	return (jacobDEQ(nb - 1) + (2 * jacobDEQ(nb - 2)));
}
//************************************* BINARY SEARCH ****************************************** */

void PmergeMe::insertloserDEQ(Element loser, std::deque<Element>& mainChain, int start, int end)
{
	int range = end - start;
	if (range == 0)
	{
        mainChain.insert(mainChain.begin() + start, loser);
		return ;
	}

    int mid = range / 2;

    if (loser.value < mainChain[mid + start].value)
        insertloserDEQ(loser, mainChain, start, mid + start);
    else
        insertloserDEQ(loser, mainChain, mid + start + 1, end);
}

void PmergeMe::BinaryInsertionDEQ(std::deque<int> jacobOrder, std::deque<Element> pend, std::deque<Element>& mainChain)
{
	std::deque<Element> orderedPend;
	std::deque<int> winPos;

	// loop through jacob deque and take the elements with its winner position in mainChain 
	for (size_t i = 0; i < jacobOrder.size(); i++)
	{
		int idx = jacobOrder[i];
		orderedPend.push_back(pend[idx]); // take ordered elements from pend
		winPos.push_back(idx + 1); // here we track winner position for each pend 
	}

	for (size_t i = 0; i < orderedPend.size(); i++)
	{
		insertloserDEQ(orderedPend[i], mainChain, 0, winPos[i]);
		for (size_t j = 0; j < winPos.size(); j++)
			winPos[j]++;
	}
}

PmergeMe::~PmergeMe(){}
