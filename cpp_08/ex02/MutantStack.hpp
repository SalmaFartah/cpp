#pragma once
#include <stack>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef T* iterator;
		MutantStack();
		MutantStack( const MutantStack& old);
		MutantStack& operator=( const MutantStack& old);
		~MutantStack();
		iterator begin();
		iterator end();
};

#include "MutantStack.tpp"
