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

std::string Intern::Names[3] =
{
    "shrubbery creation",
	"robotomy request",
	"presidential pardon"
};

AForm* (*Intern::Constructors[3])(const std::string &target) =
{
    &ShrubberyCreationForm::create,
    &RobotomyRequestForm::create,
    &PresidentialPardonForm::create
};

AForm* Intern::makeForm(std::string &formName, std::string &formTarget)
{
    for (int i = 0; i < 3; i++)
    {
        if (formName == Names[i])
        {
            std :: cout << "Intern created " << formName << std :: endl;
			return Constructors[i](formTarget);
        }
    }
    throw Intern::FormNotFoundException();
}
