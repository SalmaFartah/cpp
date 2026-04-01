#include "RPN.hpp"

bool RPN::onlySpace(const std::string& mystr)
{
	for (size_t i = 0; i < mystr.size(); i++)
	{
		if (!std::isspace(mystr[i]))
			return false;
	}
	return true;
}

RPN::RPN(char *str): inp(str)
{
	if (!str || !*str || onlySpace(inp))
		throw std::runtime_error("Error");
	for (int i = 0; str[i]; i++)
	{
		if (!std::isspace(str[i]) && (str[i + 1] && !std::isspace(str[i + 1])))
			throw std::runtime_error("Error");
	}
}
RPN::~RPN(){}
void RPN::processRpn()
{
	int a, b;
	for (size_t i = 0; i < inp.size(); i++)
	{
		if (std::isdigit(inp[i]))
		{
			std::string nb;
			nb.push_back(inp[i]);
			stk.push(atoi(nb.c_str()));
		}
		else if (stk.size() >= 2 && !std::isspace(inp[i]))
		{
			a = stk.top();
			stk.pop();
			b = stk.top();
			stk.pop();
			switch (inp[i])
			{
				case '+':
					stk.push(a + b);
					break;
				case '-':
					stk.push(b - a);
					break;
				case '*':
					stk.push(a * b);
					break;
				case '/':
					if (a == 0)
						throw std::runtime_error("Error");
					stk.push(b / a);
					break;
				default:
					throw std::runtime_error("Error");
			}
		}
		else if (!std::isspace(inp[i]))
			throw std::runtime_error("Error");
	}
	if (stk.size() > 1)
		throw std::runtime_error("Error");
	std::cout << stk.top() << std::endl;
}
