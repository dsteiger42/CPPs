/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:50:17 by dsteiger          #+#    #+#             */
/*   Updated: 2025/10/20 17:53:00 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int	main(void)
{
	const Animal *meta = new Animal();
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	cat->makeSound();
	dog->makeSound();
	meta->makeSound();
	delete meta;
	delete dog;
	delete cat;

	std::cout << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << std::endl;

	const WrongAnimal *c1 = new WrongCat();
	std::cout << c1->getType() << std::endl;
	c1->makeSound();
	delete c1;
	return (0);
}