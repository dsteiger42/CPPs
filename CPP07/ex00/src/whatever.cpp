/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:38:23 by dsteiger          #+#    #+#             */
/*   Updated: 2025/12/22 15:38:25 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/whatever.hpp"

Whatever::Whatever() {}

Whatever::Whatever(const Whatever &copy)
{
    *this = copy;
}

Whatever &Whatever::operator=(const Whatever &src)
{
    (void)src;
	return (*this);
}

Whatever::~Whatever() {}