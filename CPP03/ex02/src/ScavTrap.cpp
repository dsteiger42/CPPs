/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:58:21 by dsteiger          #+#    #+#             */
/*   Updated: 2025/10/22 14:52:45 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	_HitPoint = 100;
	_EnergyPoints = 50;
	_AttackDamage = 20;
	std::cout << "ScavTrap2 default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_Name = name;
	_HitPoint = 100;
	_EnergyPoints = 50;
	_AttackDamage = 20;
	std::cout << "> ScavTrap2 constructor activated" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &copy) : ClapTrap(copy)
{
	std::cout << "ScavTrap2 copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &copy)
{
	if (this != &copy)
	{
		ClapTrap::operator=(copy); // Reuse base class assignment
		// No additional members to assign in ScavTrap
		std::cout << "ScavTrap2 assignment operator called" << std::endl;
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap2 destructor has been called" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap2 is now in Gate Keeper mode" << std::endl;
}
