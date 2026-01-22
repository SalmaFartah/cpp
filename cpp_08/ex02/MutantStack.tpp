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
	return this->c.begin();
}

template <typename T> 
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return this->c.end();
}

template <typename T> 
MutantStack<T>::~MutantStack(){}
