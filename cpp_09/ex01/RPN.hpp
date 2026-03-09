#pragma once

#include <stack>
#include <string>
#include <iostream>
class RPN
{
private:
	std::stack<int> stk;
	std::string inp;
	RPN();
	RPN(const RPN& old);
	RPN& operator=(const RPN& old);
	bool onlySpace(const std::string& mystr);
public:
	RPN(char *);
	~RPN();

	void processRpn();
};
