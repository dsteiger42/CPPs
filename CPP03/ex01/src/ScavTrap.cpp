/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:15:51 by dsteiger          #+#    #+#             */
/*   Updated: 2025/10/20 16:52:08 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	_HitPoint = 100;
	_EnergyPoints = 50;
	_AttackDamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_Name = name;
	_HitPoint = 100;
	_EnergyPoints = 50;
	_AttackDamage = 20;
	std::cout << "> ScravTrap constructor activated" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &copy) : ClapTrap(copy)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &copy)
{
	if (this != &copy)
	{
		ClapTrap::operator=(copy); // Reuse base class assignment
		// No additional members to assign in ScavTrap
		std::cout << "ScavTrap assignment operator called" << std::endl;
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor has been called" << std::endl;
}

void ScavTrap::attack(std::string const &target)
{
	std::cout << "ScavTrap " << _Name << " attacks " << target
		<< ", causing " << _AttackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "> ScavTrap is now in Gate Keeper mode" << std::endl;
}
