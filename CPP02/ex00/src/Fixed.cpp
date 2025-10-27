/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:04:49 by dsteiger          #+#    #+#             */
/*   Updated: 2025/10/14 17:49:46 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed() : _number(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(Fixed const &copy)
{
	std::cout << "Copy constructor called\n";
	*this = copy;
}

Fixed &Fixed::operator=(Fixed const &copy)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &copy)
		this->_number = copy.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (_number);
}

void Fixed::setRawBits(int const raw)
{
	_number = raw;
}
