/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:41:27 by dsteiger          #+#    #+#             */
/*   Updated: 2025/10/20 15:38:39 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

int	main(void)
{
	ClapTrap claptrap;
	ClapTrap claptrap2(claptrap);
	ClapTrap claptrap3;
	ClapTrap claptrap4("Sauron");
	claptrap3 = claptrap;

	claptrap.attack("Sauron");
	claptrap4.takeDamage(claptrap.getAttackDamage());
	claptrap.beRepaired(1);
	std::cout << "> Energy points left: " << claptrap.getEnergyPoints() << std::endl;
	claptrap.setIncreaseAttack(2);
	claptrap.attack("Sauron");
	claptrap4.takeDamage(claptrap.getAttackDamage());
	claptrap4.getHitPoints();
	claptrap4.beRepaired(3);
    claptrap4.getHitPoints();
}