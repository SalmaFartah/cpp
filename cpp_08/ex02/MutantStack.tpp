#pragma once

template <typename T> 
MutantStack<T>::MutantStack(){}

template <typename T> 
MutantStack<T>::MutantStack( const MutantStack& old )
{
	(void)old;
}

template <typename T> 
MutantStack<T>& MutantStack<T>::operator=( const MutantStack& old )
{
	(void)old;
	return *this;
}

template <typename T> 
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return &this->top() - this->size() + 1;
}

template <typename T> 
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return &this->top() + 1;
}

template <typename T> 
MutantStack<T>::~MutantStack(){}
