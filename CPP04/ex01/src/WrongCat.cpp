/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:52:08 by dsteiger          #+#    #+#             */
/*   Updated: 2025/10/24 15:52:09 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	this->_type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal()
{
	this->_type = copy._type;
}

WrongCat &WrongCat::operator=(const WrongCat &copy)
{
	if (this != &copy)
		this->_type = copy._type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << _type << " mehhhh" << std::endl;
}
