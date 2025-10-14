/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:04:41 by dsteiger          #+#    #+#             */
/*   Updated: 2025/10/13 18:45:21 by dsteiger         ###   ########.fr       */
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
	~Fixed();
	Fixed(const int value);
	Fixed(const float value);
	int toInt(void) const;
	float toFloat(void) const;
	int getRawBits(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &value);

#endif