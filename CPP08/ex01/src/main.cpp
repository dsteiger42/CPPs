/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 17:23:27 by dsteiger          #+#    #+#             */
/*   Updated: 2026/01/07 17:29:23 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

int main()
{
    try {
        Span sp = Span(3);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

    try {
        Span sp1 = Span(10000);
        sp1.fillVector();
        std::cout << sp1.shortestSpan() << std::endl;
        std::cout << sp1.longestSpan() << std::endl;
    }
    catch(const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
    return 0;
}