/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 17:23:30 by dsteiger          #+#    #+#             */
/*   Updated: 2026/01/07 17:25:28 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

Span::Span() : _Nb(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Span::Span(unsigned int N) : _Nb(N)
{
    std::cout << "Constructor called" << std::endl;
}

Span::Span(const Span &copy)
{
    *this = copy;
}

Span &Span::operator=(const Span &src)
{
	if (this != &src) {
        _Nb = src._Nb;
        _vec = src._vec;
    }
	return (*this);
}

Span::~Span()
{
    std::cout << "Destructor called" << std::endl;
}

void Span::addNumber(int num)
{
    if(_vec.size() >= _Nb)
        throw IsFullException();
    _vec.insert(std::lower_bound(_vec.begin(), _vec.end(), num), num);
}

unsigned int Span::shortestSpan()
{
    int min;
    int span;

    if(_vec.size() < 2)
        throw NoSpanException();

    min = std::numeric_limits<int>::max();
    for(size_t i = 1; i < _vec.size(); i++)
    {
        span = _vec[i] - _vec[i - 1];
        if(span < min)
            min = span;
    }
    return min;
}

unsigned int Span::longestSpan()
{
    if(_vec.size() < 2)
        throw NoSpanException();
    return (_vec.back() - _vec.front());
}

void Span::fillVector()
{
    std::srand(std::time(0));
    while (_vec.size() < _Nb)
    {
        addNumber(std::rand());
    }
}
