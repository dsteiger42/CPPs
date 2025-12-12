/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:05:10 by dsteiger          #+#    #+#             */
/*   Updated: 2025/10/14 16:26:24 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed() : _number(0)
{
}

Fixed::Fixed(Fixed const &copy)
{
	*this = copy;
}

Fixed &Fixed::operator=(Fixed const &copy)
{
	if (this != &copy)
		this->_number = copy.getRawBits();
	return (*this);
}

Fixed::Fixed(const int value)
{
	_number = value << _fractionalBits;
}
Fixed::Fixed(const float value)
{
	_number = roundf(value * (1 << _fractionalBits));
}

Fixed::~Fixed()
{
}

bool Fixed::operator>(Fixed const &copy) const
{
	if (_number > copy._number)
		return (true);
	return (false);
}

bool Fixed::operator<(Fixed const &copy) const
{
	if (_number < copy._number)
		return (true);
	return (false);
}

bool Fixed::operator>=(Fixed const &copy) const
{
	if (_number >= copy._number)
		return (true);
	return (false);
}

bool Fixed::operator<=(Fixed const &copy) const
{
	if (_number <= copy._number)
		return (true);
	return (false);
}

bool Fixed::operator==(Fixed const &copy) const
{
	if (_number == copy._number)
		return (true);
	return (false);
}

bool Fixed::operator!=(Fixed const &copy) const
{
	if (_number != copy._number)
		return (true);
	return (false);
}

Fixed Fixed::operator+(Fixed const &copy) const
{
	return Fixed(this->toFloat() + copy.toFloat());
}

Fixed Fixed::operator-(Fixed const &copy) const
{
	return Fixed(this->toFloat() - copy.toFloat());
}

Fixed Fixed::operator*(Fixed const &copy) const
{
	return Fixed(this->toFloat() * copy.toFloat());
}

Fixed Fixed::operator/(Fixed const &copy) const
{
	return Fixed(this->toFloat() / copy.toFloat());
}

// increment first, print after
Fixed &Fixed::operator++()
{
	_number++;
	return (*this);
}

// print first, increment after
Fixed Fixed::operator++(int)
{
	Fixed	old_value;

	old_value = *this;
	_number++;
	return (old_value);
}

Fixed &Fixed::operator--()
{
	_number--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed	old_value;

	old_value = *this;
	_number--;
	return (old_value);
}

Fixed &Fixed::min(Fixed &min, Fixed &max)
{
	if (min <= max)
		return min;
	return max;
}

Fixed const &Fixed::min(const Fixed &min, const Fixed &max)
{
	if (min <= max)
		return min;
	return max;
}

Fixed &Fixed::max(Fixed &min, Fixed &max)
{
	if (min >= max)
		return min;
	return max;
}

Fixed const &Fixed::max(const Fixed &min, const Fixed &max)
{
	if (min >= max)
		return min;
	return max;
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
	return (out);
}
