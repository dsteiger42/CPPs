/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:52:37 by dsteiger          #+#    #+#             */
/*   Updated: 2025/10/24 17:32:17 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = copy._ideas[i];
}

Brain &Brain::operator=(const Brain &copy)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = copy._ideas[i];
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

std::string Brain::getIdea(int index) const
{
	if (index < 0 || index >= 100 || _ideas[index].empty())
		return ("");
	return (_ideas[index]);
}

void Brain::setIdea(int index, std::string idea)
{
	if (index < 0 || index >= 100)
	{
		std::cout << "Error: index outside bounderies." << std::endl;
		return ;
	}
	_ideas[index] = idea;
}
