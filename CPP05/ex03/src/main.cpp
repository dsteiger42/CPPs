/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 19:25:41 by dsteiger          #+#    #+#             */
/*   Updated: 2025/11/04 17:44:52 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/Intern.hpp"

int	main(void)
{
	try
	{
		Intern intern;
		std::string formName = "robotomy request";
		std::string formTarget = "Bin Laden";
		AForm *form = intern.makeForm(formName, formTarget);
		Bureaucrat bur1("N1", 140);
		if(form)
		{
			ShrubberyCreationForm shrubberyForm("Burro");
			RobotomyRequestForm robotomyForm("OK");
			PresidentialPardonForm pardonForm("Esperto");
			
			bur1.signForm(shrubberyForm);
			bur1.signForm(robotomyForm);
			bur1.signForm(pardonForm);
			
			bur1.executeForm(shrubberyForm);
			std::cout << std::endl;
			bur1.executeForm(robotomyForm);
			std::cout << std::endl;
			bur1.executeForm(pardonForm);
			delete form;
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}