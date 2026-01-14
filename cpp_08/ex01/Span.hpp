#pragma once
#include <vector>
#include <algorithm>
#include <iostream>

class Span
{
private:
    std::vector<int> elements;
    unsigned int MaxLength;
public:
    Span();
    Span( unsigned int N );
    Span( const Span& old );
    Span& operator=( const Span& old );
    void addNumber( int Number );
    int shortestSpan();
    int longestSpan();

    class SpanIsFull : public std::exception
    {
        const char* what() const throw();
    };
    ~Span();
};
