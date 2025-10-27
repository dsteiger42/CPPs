/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:57:39 by dsteiger          #+#    #+#             */
/*   Updated: 2025/10/22 15:16:10 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap()
{
    _Name = "Aegon";
	_HitPoint = FragTrap::_HitPoint;
	_EnergyPoints = ScavTrap::_EnergyPoints;
	_AttackDamage = FragTrap::_AttackDamage;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name), FragTrap(name)
{
	_Name = name;
    ClapTrap::_Name = this->_Name + "_clap_name";
	_HitPoint = FragTrap::_HitPoint;
	_EnergyPoints = ScavTrap::_EnergyPoints;
	_AttackDamage = FragTrap::_AttackDamage;
	std::cout << "> DiamondTrap constructor activated" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy), _Name(copy._Name)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &copy)
{
	if (this != &copy)
	{
		ClapTrap::operator=(copy); // Reuse base class assignment
		// No additional members to assign in DiamondTrap
		std::cout << "DiamondTrap assignment operator called" << std::endl;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor has been called" << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << _Name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::_Name << std::endl;
}