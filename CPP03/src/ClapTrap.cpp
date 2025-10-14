/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:41:41 by dsteiger          #+#    #+#             */
/*   Updated: 2025/10/14 19:32:15 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	_Name = "Default";
	_HitPoint = 10;
	_EnergyPoints = 10;
	_AttackDamage = 0;
	std::cout << "Default constructor activated" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &copy)
{
	_Name = copy._Name;
	_HitPoint = copy._HitPoint;
	_EnergyPoints = copy._EnergyPoints;
	_AttackDamage = copy._AttackDamage;
	std::cout << "Copy constructor activated" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &copy)
{
	if (this != &copy)
	{
		_Name = copy._Name;
		_HitPoint = copy._HitPoint;
		_EnergyPoints = copy._EnergyPoints;
		_AttackDamage = copy._AttackDamage;
	}
	std::cout << "Operator constructor activated" << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor activated" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (_HitPoint < 1)
	{
		std::cout << "The enemy is dead\n";
		return ;
	}
	if (_EnergyPoints < 1)
	{
		std::cout << "You have no energy. Try cocaine\n";
		return ;
	}
	_EnergyPoints--;
	std::cout << "ClapTrap" << _Name << "attacks" << target
				<< ", causing" << _AttackDamage << "points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_HitPoint < 1)
	{
		std::cout << "The enemy is dead\n";
		return ;
	}
	if (_EnergyPoints < 1)
	{
		std::cout << "You have no energy. Try cocaine\n";
		return ;
	}
	_HitPoint++;
	_EnergyPoints--;
	std::cout << "ClapTrap" << _Name << "repairs itself"
				<< ", causing" << _HitPoint << "hp increase!\n";
}
