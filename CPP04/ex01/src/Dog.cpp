/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:52:02 by dsteiger          #+#    #+#             */
/*   Updated: 2025/10/24 17:56:35 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

// allocate for _brain because in getBrain we would get an uninitialized pointer
Dog::Dog() : Animal()
{
	this->_type = "Dog";
	this->_brain = new Brain();
	std::cout << GREEN << "Dog default constructor called" << RESET << std::endl;
}

Dog::Dog(const Dog &copy) : Animal()
{
	this->_type = copy._type;
	this->_brain = new Brain(*copy._brain);
}

Dog &Dog::operator=(const Dog &copy)
{
	if (this != &copy)
	{
		this->_type = copy._type;
		delete this->_brain;
		this->_brain = new Brain(*copy._brain);
	}
	return (*this);
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << RED << "Dog destructor called" << RESET << std::endl;
}

void Dog::makeSound() const
{
	std::cout << _type << "-> ruf ruf" << std::endl;
}

Brain *Dog::getBrain() const
{
    return this->_brain;
}
