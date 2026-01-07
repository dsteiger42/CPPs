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
# define SPAN_H

# include <iostream>
# include <vector>

class Span
{
    private:
	    unsigned int _Nb; // max number of integers
	    std::vector<int> _vec; // the integers themselves

    public:
        Span();
        Span(unsigned int N);
        Span(const Span &copy);
        Span &operator=(const Span &src);
        ~Span();

        void addNumber(int num);
        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;

        class FullException : public std::exception
        {
            public:
                const char* what() const throw() {
                    return "Span is full\n";
                }
        };
        class NoSpanException : public std::exception
        {
            public:
                const char* what() const throw() {
                    return "Not enough numbers to calculate a span\n";
                }
        };
};

#endif