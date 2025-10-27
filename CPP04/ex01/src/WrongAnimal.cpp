/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:52:06 by dsteiger          #+#    #+#             */
/*   Updated: 2025/10/24 15:52:07 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	this->_type = copy._type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy)
{
	if (this != &copy)
		this->_type = copy._type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << _type << " wassup" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (this->_type);
}
