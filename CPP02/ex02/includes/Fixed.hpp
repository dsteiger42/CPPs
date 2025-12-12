/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:05:06 by dsteiger          #+#    #+#             */
/*   Updated: 2025/10/14 16:42:11 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath>
# include <iostream>

class Fixed
{
  private:
	int _number;
	static const int _fractionalBits = 8;

  public:
	Fixed();
	Fixed(Fixed const &copy);
	Fixed &operator=(Fixed const &copy);
	Fixed(const int value);
	Fixed(const float value);
	~Fixed();

	Fixed operator+(Fixed const &copy) const;
	Fixed operator-(Fixed const &copy) const;
	Fixed operator*(Fixed const &copy) const;
	Fixed operator/(Fixed const &copy) const;

	bool operator>(Fixed const &copy) const;
	bool operator<(Fixed const &copy) const;
	bool operator>=(Fixed const &copy) const;
	bool operator<=(Fixed const &copy) const;
	bool operator==(Fixed const &copy) const;
	bool operator!=(Fixed const &copy) const;

	Fixed &operator++(void);
	Fixed operator++(int);
	Fixed &operator--(void);
	Fixed operator--(int);

	static Fixed &min(Fixed &min, Fixed &max);
	static Fixed const &min(const Fixed &min, const Fixed &max);
	static Fixed &max(Fixed &min, Fixed &max);
	static Fixed const &max(const Fixed &min, const Fixed &max);

	int toInt(void) const;
	float toFloat(void) const;
	int getRawBits(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &value);

#endif