/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 17:23:13 by dsteiger          #+#    #+#             */
/*   Updated: 2025/12/22 17:23:14 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/easyfind.hpp"

EasyFind::EasyFind() {}

EasyFind::EasyFind(const EasyFind &copy)
{
    *this = copy;
}

EasyFind &EasyFind::operator=(const EasyFind &src)
{
	(void)src;
	return (*this);
}

EasyFind::~EasyFind() {}