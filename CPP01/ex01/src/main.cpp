/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:05:51 by dsteiger          #+#    #+#             */
/*   Updated: 2025/09/01 17:21:10 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int main(void)
{
    int n;
    std::cout << "Enter the number of zombies: ";
    std::cin >> n;
    Zombie* horde = zombieHorde(n, "Shane");
    for (int i = 0; i < n; i++)
        horde[i].announce();
    delete[] horde;
    return 0;
}