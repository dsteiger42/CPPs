/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 17:23:30 by dsteiger          #+#    #+#             */
/*   Updated: 2025/12/22 18:47:48 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

Span::Span()
{
    std::cout << "Default constructor called" << std::endl;
}

Span::Span(unsigned int N) : _Nb(N) {}

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
    if(_vec.size() < _Nb)
        _vec.push_back(num);
    else
        throw FullException();
}

unsigned int Span::shortestSpan() const
{
    if(_Nb <= 1)
        throw NoSpanException();
}

// maior numero - menor numero
unsigned int Span::longestSpan() const
{
    if(_Nb <= 1)
        throw NoSpanException();
}