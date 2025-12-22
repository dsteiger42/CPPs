#ifndef SPAN_H
#define SPAN_H

#include <iostream>

class Span
{
    public:
        Span();
        Span(const Span &copy);
        Span &operator=(const Span &src);
        ~Span();

        void addNumber();
        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;
};

#endif