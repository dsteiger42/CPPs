/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 20:29:14 by dsteiger          #+#    #+#             */
/*   Updated: 2025/11/04 17:42:53 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &copy)
{
    (void)copy;
}

Intern &Intern::operator=(const Intern &copy)
{
    (void)copy;
	return (*this);
}

Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}

AForm *Intern::makeForm(std::string &formName, std::string &formTarget)
{
	if (formName.empty())
	{
		std::cerr << "Form name does not exist." << std::endl;
		return (NULL);
	}
	if (formName == "shrubbery creation")
	{
		std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
		return (new ShrubberyCreationForm(formTarget));
	}
	else if (formName == "robotomy request")
	{
		std::cout << "Intern creates RobotomyRequestForm" << std::endl;
		return (new RobotomyRequestForm(formTarget));
	}
	else if (formName == "presidential pardon")
	{
		std::cout << "Intern creates PresidentialPardonForm" << std::endl;
		return (new PresidentialPardonForm(formTarget));
	}
	else
	{
		std::cerr << "Intern could not find the form: " << formName << std::endl;
		return (NULL);
	}
}
