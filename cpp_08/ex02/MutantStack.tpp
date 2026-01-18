#pragma once

template <typename T> MutantStack<T>::MutantStack(){}

template <typename T> typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return &this->top() - this->size() + 1;
}

template <typename T> typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return &this->top();
}

template <typename T> MutantStack<T>::~MutantStack(){}