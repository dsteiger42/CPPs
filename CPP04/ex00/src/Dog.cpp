/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:52:23 by dsteiger          #+#    #+#             */
/*   Updated: 2025/10/20 18:24:43 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog() : Animal()
{
	this->_type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal()
{
	this->_type = copy._type;
}

Dog &Dog::operator=(const Dog &copy)
{
	if (this != &copy)
		this->_type = copy._type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << _type << "-> ruf ruf" << std::endl;
}
