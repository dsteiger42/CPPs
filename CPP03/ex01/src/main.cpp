/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:15:47 by dsteiger          #+#    #+#             */
/*   Updated: 2025/10/16 18:15:48 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

int	main(void)
{
	ScavTrap scavtrap;
	ScavTrap scavtrap2(scavtrap);
	ScavTrap scavtrap3;
	ScavTrap scavtrap4("Sauron");
	scavtrap3 = scavtrap;

	scavtrap.guardGate();
	scavtrap.attack("Sauron");
	scavtrap4.takeDamage(scavtrap.getAttackDamage());
	scavtrap4.beRepaired(40);
	std::cout << "> Energy points left: " << scavtrap.getEnergyPoints() << std::endl;
	scavtrap.setIncreaseAttack(2);
	scavtrap.attack("Sauron");
	scavtrap4.takeDamage(scavtrap.getAttackDamage());
	scavtrap4.getHitPoints();
	scavtrap4.beRepaired(3);
	scavtrap4.getHitPoints();
}