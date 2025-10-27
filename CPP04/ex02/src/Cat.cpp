/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:52:39 by dsteiger          #+#    #+#             */
/*   Updated: 2025/10/24 17:57:16 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat() : Animal()
{
	this->_type = "Cat";
	this->_brain = new Brain();
	std::cout << YELLOW << "Cat default constructor called" << RESET << std::endl;
}

Cat::Cat(const Cat &copy) : Animal()
{
	this->_type = copy._type;
	this->_brain = new Brain(*copy._brain);
}

Cat &Cat::operator=(const Cat &copy)
{
	if (this != &copy)
	{
		this->_type = copy._type;
		delete this->_brain;
		this->_brain = new Brain(*copy._brain);	
	}
	return (*this);
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << MAGENTA << "Cat destructor called" << RESET << std::endl;
}

void Cat::makeSound() const
{
	std::cout << _type << "-> meaw meaw" << std::endl;
}

Brain *Cat::getBrain() const
{
    return this->_brain;
}
