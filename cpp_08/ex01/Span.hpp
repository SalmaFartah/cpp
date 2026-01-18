#pragma once
#include <vector>
#include <algorithm>
#include <iostream>

class Span
{
    private:
        typedef std::vector<int>::iterator  _it;

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

        template <typename iterator>
        void addMultiNumbers(iterator begin, iterator end)
        {
            int dis = std::distance(begin, end);
	        if (dis <= 0)
	        	throw std::logic_error("invalid range !");
	        if (static_cast<unsigned int>(dis) > MaxLength - elements.size())
	        	throw SpanIsFull("Not enough space found !");
	        elements.insert(elements.end(), begin, end);
        }

        class SpanIsFull : public std::exception
        {
            private:
                std::string message;
            public:
                SpanIsFull( const std::string& message );
                const char* what() const throw();
                ~SpanIsFull() throw();
        };

        class SpanNotFound : public std::exception
        {
            const char* what() const throw();
        };
        ~Span();
};
