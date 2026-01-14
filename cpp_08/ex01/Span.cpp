#include "Span.hpp"

Span::Span(){}

Span::Span( unsigned int N )
{
	MaxLength = N;
}

Span::Span( const Span& old )
{
	this->elements = old.elements;
	this->MaxLength = old.MaxLength;
}

Span& Span::operator=( const Span& old )
{
	this->elements = old.elements;
	this->MaxLength = old.MaxLength;
	return *this;
}

void Span::addNumber( int Number )
{
	if (elements.size() == MaxLength)
		throw SpanIsFull();
	elements.push_back(Number);
}

int Span::longestSpan()
{
	std::vector<int>::iterator maxElement =  std::max_element(elements.begin(), elements.end());
	std::vector<int>::iterator minElement = std::min_element(elements.begin(), elements.end());
	return *maxElement - *minElement;
}

const char *Span::SpanIsFull::what() const throw()
{
	return "Span is full !";
}

Span::~Span()
{
}
