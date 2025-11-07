/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 19:25:53 by dsteiger          #+#    #+#             */
/*   Updated: 2025/11/03 20:23:10 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 72,
	45), _target("DefaultTarget")
{
	std::cout << "Default Robotomy constructor called." << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request Form",
	72, 45), _target(target)
{
	std::cout << "Robotomy constructor called." << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm("Robotomy Request Form",
	72, 45), _target(copy._target)
{
}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	if (this != &copy)
		_target = copy._target;
	return (*this);
}
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Robotomy destructor called." << std::endl;
}

void RobotomyRequestForm::beExecuted() const
{
	std::srand(std::time(NULL));
	std::cout << "Trrrrr trrrrrr" << std::endl;
	if (rand() % 2)
		std::cout << _target << " has been robotomized successfully." << std::endl;
	else
		std::cout << _target << " robotomy failed." << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	AForm::execute(executor);
	beExecuted();
}

AForm* RobotomyRequestForm::create(const std::string &target)
{
    return new RobotomyRequestForm(target);
}
