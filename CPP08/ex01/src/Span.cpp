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

Span::Span() {}

Span::Span(unsigned int N)
{
    
}

Span::Span(const Span &copy)
{
    *this = copy;
}

Span &Span::operator=(const Span &src)
{
	(void)src;
	return (*this);
}

Span::~Span() {}

void Span::addNumber(int num)
{

}

unsigned int Span::shortestSpan() const
{
    if(_N <= 1)
        throw;
}

// maior numero - menor numero
unsigned int Span::longestSpan() const
{
    if(_N <= 1)
        throw;
}