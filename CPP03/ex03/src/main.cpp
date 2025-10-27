/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:57:47 by dsteiger          #+#    #+#             */
/*   Updated: 2025/10/22 15:19:08 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap diamond;
	DiamondTrap diamond2("Darte");
	diamond.attack("Sauron");
	diamond2.attack("Sauron");
	diamond.whoAmI();
}