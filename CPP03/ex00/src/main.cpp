/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:41:27 by dsteiger          #+#    #+#             */
/*   Updated: 2025/10/14 19:17:46 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

int main(void)
{
    ClapTrap claptrap;
    ClapTrap claptrap2(claptrap);
    ClapTrap claptrap3;
    claptrap3 = claptrap;

    claptrap.attack("DOG");
    claptrap.takeDamage(1);
    claptrap.beRepaired(1);
    std::cout << "> nergy points left: " << claptrap.getEnergyPoints() << std::endl;
    claptrap.increaseAttack(3);
    claptrap.attack("DOG");
}