/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 19:25:41 by dsteiger          #+#    #+#             */
/*   Updated: 2025/11/03 20:22:57 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

int	main(void)
{
	try
	{
		Bureaucrat bur1("N1", 151);

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
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n-------------------\n" << std::endl;

	try
	{
		Bureaucrat bur2("N2", -1);

		ShrubberyCreationForm shrubberyForm("Burro");
		RobotomyRequestForm robotomyForm("OK");
		PresidentialPardonForm pardonForm("Esperto");

		bur2.signForm(shrubberyForm);
		bur2.signForm(robotomyForm);
		bur2.signForm(pardonForm);
		std::cout << std::endl;

		bur2.executeForm(shrubberyForm);
		std::cout << std::endl;
		bur2.executeForm(robotomyForm);
		std::cout << std::endl;
		bur2.executeForm(pardonForm);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n-------------------\n" << std::endl;

	try
	{
		Bureaucrat bur3("N3", 2);

		ShrubberyCreationForm shrubberyForm("Burro");
		RobotomyRequestForm robotomyForm("OK");
		PresidentialPardonForm pardonForm("Esperto");

		bur3.signForm(shrubberyForm);
		bur3.signForm(robotomyForm);
		bur3.signForm(pardonForm);
		std::cout << std::endl;

		bur3.executeForm(shrubberyForm);
		std::cout << std::endl;
		bur3.executeForm(robotomyForm);
		std::cout << std::endl;
		bur3.executeForm(pardonForm);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n-------------------\n" << std::endl;

	try
	{
		Bureaucrat bur4("N4", 80);

		ShrubberyCreationForm shrubberyForm("Burro");
		RobotomyRequestForm robotomyForm("OK");
		PresidentialPardonForm pardonForm("Esperto");

		bur4.signForm(shrubberyForm);
		bur4.signForm(robotomyForm);
		bur4.signForm(pardonForm);
		std::cout << std::endl;

		bur4.executeForm(shrubberyForm);
		std::cout << std::endl;
		bur4.executeForm(robotomyForm);
		std::cout << std::endl;
		bur4.executeForm(pardonForm);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}