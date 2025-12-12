/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:04:47 by dsteiger          #+#    #+#             */
/*   Updated: 2025/10/10 19:13:40 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANONICAL_HPP
# define CANONICAL_HPP

#include <iostream>

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
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif