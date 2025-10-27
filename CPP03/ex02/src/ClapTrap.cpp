/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:58:15 by dsteiger          #+#    #+#             */
/*   Updated: 2025/10/20 17:58:16 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	_Name = "Napolean";
	_HitPoint = 10;
	_EnergyPoints = 10;
	_AttackDamage = 0;
	std::cout << YELLOW << "> ClapTrap2 default constructor activated" << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	_Name = name;
	_HitPoint = 10;
	_EnergyPoints = 10;
	_AttackDamage = 0;
	std::cout << YELLOW << "> ClapTrap2 constructor activated" << RESET << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &copy)
{
	_Name = copy._Name;
	_HitPoint = copy._HitPoint;
	_EnergyPoints = copy._EnergyPoints;
	_AttackDamage = copy._AttackDamage;
	std::cout << GREEN << "> ClapTrap2 copy constructor activated" << RESET << std::endl;
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
	std::cout << BLUE << "> ClapTrap2 assignment operator activated" << RESET << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << RED << "> ClapTrap2 destructor activated" << RESET << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (_HitPoint < 1)
	{
		std::cout << "> The enemy is dead\n";
		return ;
	}
	if (_EnergyPoints < 1)
	{
		std::cout << "> You have no energy. Try cocaine\n";
		return ;
	}
	_EnergyPoints--;
	std::cout << _Name << " attacks " << target
				<< ", causing " << _AttackDamage << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_HitPoint < 1)
	{
		std::cout << _Name << " is dead!" << std::endl;
		return ;
	}
	_HitPoint -= amount;
	std::cout << _Name << " took a hit and lost " << amount << "hp!\n";
	if (_HitPoint < 1)
	{
		std::cout << _Name << " died!" << std::endl;
		_HitPoint = 0;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_HitPoint < 1)
    {
		std::cout << _Name << " is dead!\n";
		return;
	}
	if (_EnergyPoints < 1)
    {
		std::cout << "> You have no energy. Try cocaine\n";
		return;
	}
	_HitPoint += amount;
	if (_HitPoint > 100)
		_HitPoint = 100;
	_EnergyPoints--;
	std::cout << _Name << " repairs itself and gained " << amount << "hp!" << std::endl;
	std::cout << _Name << " now has " << _HitPoint << "hp!" << std::endl;
}

void ClapTrap::setIncreaseAttack(unsigned int amount)
{
	//std::cout << "> Attack damage before boost " << _AttackDamage << std::endl;
	_AttackDamage += amount;
	std::cout << _Name << " improves his power by " << amount << " damage!" << std::endl;
	//std::cout << "> Attack damage after boost " << _AttackDamage << std::endl;
}

int ClapTrap::getEnergyPoints() const
{
	return (_EnergyPoints);
}

int ClapTrap::getAttackDamage() const
{
	if (_HitPoint < 1)
	{
		std::cout << _Name << " is dead!" << std::endl;
		return 0;
	}
	std::cout << _Name << " has " << _AttackDamage << " attack damage!" << std::endl;
	return (_AttackDamage);
}

int ClapTrap::getHitPoints() const
{
	if (_HitPoint < 1)
	{
		std::cout << _Name << " is dead!" << std::endl;
		return 0;
	}
	if (_HitPoint >= 10)
	{
		std::cout << _Name << " has " << _HitPoint << " hp!" << std::endl;
	}
	else
		std::cout << _Name << " has " << _HitPoint << " hp!" << std::endl;
	return _HitPoint;
}
