#include <iostream>
#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;

	mstack.push(5);
    mstack.push(10);
    mstack.push(15);
    std::cout << "Top element: " << mstack.top() << std::endl;

    mstack.pop();
    std::cout << "Top after pop: " << mstack.top() << std::endl;

    mstack.push(20);
    mstack.push(25);
    std::cout << "MutantStack elements: ";
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    for (; it != ite; ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

	MutantStack<int> emptyStack;
    std::cout << "\nEmpty stack size: " << emptyStack.size() << std::endl;

    if (emptyStack.begin() == emptyStack.end())
        std::cout << "the stack is empty !" << std::endl;

    return 0;
}
