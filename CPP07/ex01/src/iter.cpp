/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:38:38 by dsteiger          #+#    #+#             */
/*   Updated: 2025/12/22 15:38:39 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/iter.hpp"

Iter::Iter() {}

Iter::Iter(const Iter &copy)
{
    *this = copy;
}

Iter &Iter::operator=(const Iter &src)
{
    (void)src;
	return (*this);
}

Iter::~Iter() {}