/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:58:17 by dsteiger          #+#    #+#             */
/*   Updated: 2025/10/20 17:58:18 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	_HitPoint = 100;
	_EnergyPoints = 100;
	_AttackDamage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_Name = name;
	_HitPoint = 100;
	_EnergyPoints = 100;
	_AttackDamage = 30;
	std::cout << "> FragTrap constructor activated" << std::endl;
}

FragTrap::FragTrap(FragTrap const &copy) : ClapTrap(copy)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &copy)
{
	if (this != &copy)
	{
		ClapTrap::operator=(copy); // Reuse base class assignment
		// No additional members to assign in FragTrap
		std::cout << "FragTrap assignment operator called" << std::endl;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor has been called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << _Name << " requested an high-five!" << std::endl;
}
