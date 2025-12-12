/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:30:48 by dsteiger          #+#    #+#             */
/*   Updated: 2025/09/01 18:54:37 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

Weapon::Weapon() : _type("unknown")
{
}

Weapon::Weapon(const std::string &type) : _type(type)
{
}
Weapon::~Weapon()
{
}

std::string Weapon::getType() const
{
    return _type;
}

void Weapon::setType(const std::string &value)
{
    _type = value;
}
