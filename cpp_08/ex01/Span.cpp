#include "Span.hpp"

Span::Span(): MaxLength(0){}

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
		throw SpanIsFull("Span is full !");
	elements.push_back(Number);
}

int Span::shortestSpan()
{
	if (!elements.size() || elements.size() == 1)
		throw SpanNotFound();

	int shortSpan = INT_MAX;
	for (size_t i = 0; i < elements.size(); i++)
	{
		for (size_t j = i + 1; j < elements.size(); j++)
		{
			if (std::abs(elements[i] - elements[j]) < shortSpan)
				shortSpan = std::abs(elements[i] - elements[j]);
		}
	}
	return shortSpan;
}

int Span::longestSpan()
{
	if (!elements.size() || elements.size() == 1)
		throw SpanNotFound();
	_it maxElement =  std::max_element(elements.begin(), elements.end());
	_it minElement = std::min_element(elements.begin(), elements.end());
	return *maxElement - *minElement;
}


const char *Span::SpanIsFull::what() const throw()
{
	return message.c_str();
}

Span::SpanIsFull::SpanIsFull(const std::string& message)
{
	this->message = message;
}

Span::SpanIsFull::~SpanIsFull() throw(){}

const char *Span::SpanNotFound::what() const throw()
{
	return "Span not found !";
}

Span::~Span(){}
