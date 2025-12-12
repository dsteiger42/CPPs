/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:02:12 by dsteiger          #+#    #+#             */
/*   Updated: 2025/09/01 14:04:27 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

// heap objects need to be deleted "by hand". If I dont store in a variable, ill lose the reference and will not be able to access and delete later.
int main(void)
{
    Zombie *zombie1 = newZombie("Shane");
    randomChump("Rick");
    delete zombie1;
}