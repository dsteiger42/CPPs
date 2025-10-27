/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:58:19 by dsteiger          #+#    #+#             */
/*   Updated: 2025/10/20 17:58:20 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

int main(void)
{
    FragTrap fragtrap;
	FragTrap fragtrap2(fragtrap);
	FragTrap fragtrap3;
	FragTrap fragtrap4("Sauron");
	fragtrap3 = fragtrap;

	fragtrap.highFivesGuys();
	fragtrap.attack("Sauron");
	fragtrap4.takeDamage(fragtrap.getAttackDamage());
	fragtrap4.beRepaired(40);
	std::cout << "> Energy points left: " << fragtrap.getEnergyPoints() << std::endl;
	fragtrap.setIncreaseAttack(2);
	fragtrap.attack("Sauron");
	fragtrap4.takeDamage(fragtrap.getAttackDamage());
	fragtrap4.getHitPoints();
	fragtrap4.beRepaired(3);
	fragtrap4.getHitPoints();
}