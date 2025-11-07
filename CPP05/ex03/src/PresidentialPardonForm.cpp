/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 19:25:48 by dsteiger          #+#    #+#             */
/*   Updated: 2025/11/03 20:23:05 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form",
	25, 5), _target("DefaultTarget")
{
	std::cout << "Default Presidential constructor called." << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon Form",
	25, 5), _target(target)
{
	std::cout << "Presidential constructor called." << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm("Presidential Pardon Form",
	25, 5), _target(copy._target)
{
}
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	if (this != &copy)
		_target = copy._target;
	return (*this);
}
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Presidential destructor called." << std::endl;
}

void PresidentialPardonForm::beExecuted() const
{
	std::cout << _target << " as been pardoned by Zaphod Beeblebrox." << std::endl;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	AForm::execute(executor);
	beExecuted();
}

AForm* PresidentialPardonForm::create(const std::string &target)
{
    return new PresidentialPardonForm(target);
}
