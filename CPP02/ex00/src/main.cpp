/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:04:54 by dsteiger          #+#    #+#             */
/*   Updated: 2025/10/14 17:52:41 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Floating point numbers
/*
The difference between this data types is that some of them are more trustworthy when using bigger numbers.
Ex: 100000000000 / 3
	-> the float will give you 6 numbers correct and then trash values. The double 15 numbers and longe double 18.
You can confirm this by adding the library <float.h> and printing this:

float -> std::cout << FLT_DIG;
double -> std::cout << DBL_DIG;
long double -> std::cout << LDBL_DIG;
*/

#include "../includes/Fixed.hpp"

int	main(void)
{
	Fixed a;
	Fixed b(a);
	Fixed c;
	c = b; // this calls the assignment operator
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return (0);
}