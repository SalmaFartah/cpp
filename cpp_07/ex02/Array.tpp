#pragma once

template <typename T>
Array<T>::Array(): array(NULL), _size_(0){}

template <typename T>
Array<T>::Array( unsigned int n )
{
	array = new T[n];
	_size_ = n;
}

template <typename T>
Array<T>::Array( const Array& old )
{
	_size_ = old._size_;
	this->array = new T[old._size_];
	for (int i = 0; i < old._size_; i++)
		this->array[i] = old.array[i];
}

template <typename T>
Array<T>& Array<T>::operator=( const Array& old )
{
	if (this == &old)
		return *this;
	delete this->array;
	_size_ = old._size_;
	this->array = new T[old._size_];
	for (int i = 0; i < old._size_; i++)
	{
		this->array[i] = old.array[i];
	}
	return *this;
}

template <typename T>
int Array<T>::size() const
{
	return _size_;
}

template<typename T>
T& Array<T>::operator[]( int n )
{
	if (n < 0 || n >= _size_)
		throw std::out_of_range("indexing out of bounds !");
	return array[n];
}

template<typename T>
const T& Array<T>::operator[]( int n ) const
{
	if (n < 0 || n >= _size_)
		throw std::out_of_range("indexing out of bounds !");
	return array[n];
}

template <typename T> Array<T>::~Array()
{
	delete[] array;
}
