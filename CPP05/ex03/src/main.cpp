/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 19:25:41 by dsteiger          #+#    #+#             */
/*   Updated: 2025/11/05 19:55:40 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/Intern.hpp"

int main(void)
{
	try
	{
		Intern intern;
		Bureaucrat bur1("N1", 2);

		std::string formName = "robotomy request";
		std::string formTarget = "Bin Laden";

		AForm *form = intern.makeForm(formName, formTarget);
		if (form)
		{
			std::cout << "\n--------------------\n" << std::endl;
			bur1.signForm(*form);
			bur1.executeForm(*form);

			std::cout << "\n--------------------\n" << std::endl;

			ShrubberyCreationForm shrubberyForm("Burro");
			RobotomyRequestForm robotomyForm("Menos Burro");
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
	return 0;
}
