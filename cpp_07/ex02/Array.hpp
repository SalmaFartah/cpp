#pragma once
#include <iostream>

template <typename T>
class Array
{
	T *array;
	int _size_;
public:
	Array();
	Array( unsigned int n );
	Array ( const Array& old );
	Array& operator=( const Array& old );
	T& operator[]( int n );
	const T& operator[]( int n ) const ;
	int size( void ) const;
	~Array();
};

#include "Array.tpp"
