/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 19:25:29 by dsteiger          #+#    #+#             */
/*   Updated: 2025/11/05 19:45:59 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "../includes/AForm.hpp"
# include "../includes/Bureaucrat.hpp"
# include <cstdlib>
# include <ctime>
# include <fstream>
# include <iostream>
# include <math.h>
# include <string>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define RESET "\033[0m"

class ShrubberyCreationForm : public AForm
{
  private:
	std::string _target;

  public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &copy);
	~ShrubberyCreationForm();
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);
	void beExecuted() const;
	void execute(const Bureaucrat &executor) const;
    static AForm* create(const std::string &target);
	class FileCantOpenException : public std::exception
	{
		public:
			const char *what() const throw()
			{
				return "Error: could not open file for writing.";
			}
	};
};
#endif
