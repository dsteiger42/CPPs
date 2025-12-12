/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:06:07 by dsteiger          #+#    #+#             */
/*   Updated: 2025/10/13 17:23:00 by dsteiger         ###   ########.fr       */
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

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called\n";
	_number = value << _fractionalBits;
	// _number = value * 256;
	// _number = value(ex:42) * 2^_fractionalBits
}
Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called\n";
	_number = roundf(value * (1 << _fractionalBits));	
}

int Fixed::toInt(void) const
{
	return _number >> _fractionalBits;
}

float Fixed::toFloat(void) const
{
	return (float)_number / (1 << _fractionalBits);
}

int Fixed::getRawBits(void) const
{
	return (_number);
}

std::ostream &operator<<(std::ostream &out, const Fixed &value)
{
	out << value.toFloat();
	return out;
}