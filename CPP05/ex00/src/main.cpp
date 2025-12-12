/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:04:34 by dsteiger          #+#    #+#             */
/*   Updated: 2025/10/31 18:36:59 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

// e.what -> is what prints std::exceptions
/* 
Se alterar valores da grade, fazer dentro do try,
senao, caso o valor seja fora do range, da merda.
*/

int	main(void)
{
	Bureaucrat bur("Bur", 150);
	std::cout << bur.getName() << std::endl;
	std::cout << bur.getGrade() << std::endl;
	bur.setGrade(30);
	std::cout << bur.getGrade() << std::endl;
	bur.setGrade(150);
	try
	{
		bur.incrementGrade(5);
		std::cout << bur.getGrade() << std::endl;

 		std::cout << "\n-------------------\n" << std::endl;
		
		bur.decreamentGrade(10);
 		std::cout << bur.getGrade() << std::endl;
		bur.setGrade(30);
		std::cout << bur.getGrade() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "wtf!\n" << e.what() << std::endl;
	}

	std::cout << "\n-------------------\n" << std::endl;
	
	try
	{
		Bureaucrat bur1("Bur1", 200);
	}
	catch (const std::exception &e)
	{
		std::cerr << "1st case exception.\n" << e.what() << std::endl;
	}

	std::cout << "\n-------------------\n" << std::endl;

	try
	{
		Bureaucrat bur1("Bur1", 0);
	}
	catch (const std::exception &e)
	{
		std::cerr << "2st case exception.\n" << e.what() << std::endl;
	}

	std::cout << "\n-------------------\n" << std::endl;

	try
	{
		Bureaucrat bur2("Bur2", 130);
        std::cout << bur2 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n-------------------\n" << std::endl;

	// multiple exceptions
	try
	{
		Bureaucrat bur3("Bur3", 160);
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "Error: Grade too high\n" << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "Error: Grade too low\n" << e.what() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: Default exception\n" << e.what() << std::endl;
	}

	std::cout << "\n-------------------\n" << std::endl;

}