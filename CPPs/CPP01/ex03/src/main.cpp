/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:30:39 by dsteiger          #+#    #+#             */
/*   Updated: 2025/09/01 19:01:48 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanA.hpp"
#include "../includes/HumanB.hpp"
#include "../includes/Weapon.hpp"

int main (void)
{
    Weapon gun("sword");                // Weapon created, type = "sword"
    HumanA Aragorn("Aragorn", gun);     // HumanA gets a reference to gun
    Aragorn.attack();                   // 
    gun.setType("big sword");
    Aragorn.attack();
    std::cout << std::endl;

    HumanB Legolas("Legolas");
    Legolas.attack();
    Weapon bow("bow");
    Legolas.setWeapon(bow);
    Legolas.attack();

    return 0;
}