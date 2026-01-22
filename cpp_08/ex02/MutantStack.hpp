#pragma once
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::deque<T>::iterator iterator;
		MutantStack();
		MutantStack( const MutantStack& old );
		MutantStack& operator=( const MutantStack& old );
		iterator begin();
		iterator end();
		~MutantStack();
};

#include "MutantStack.tpp"
