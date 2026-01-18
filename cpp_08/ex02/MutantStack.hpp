#pragma once
#include <stack>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
    private:
        
    public:
        MutantStack();
        ~MutantStack();
        class iterator : public std::__wrap_iter<T*>
        {
        };
        iterator& begin();
        iterator& end();

};

#include "MutantStack.tpp"
