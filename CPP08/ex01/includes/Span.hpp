/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 17:23:22 by dsteiger          #+#    #+#             */
/*   Updated: 2025/12/22 18:47:12 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
#define SPAN_H

#include <iostream>

class Span
{
    private:
        unsigned int _N;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span &copy);
        Span &operator=(const Span &src);
        ~Span();

        void addNumber(int num);
        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;
};

#endif