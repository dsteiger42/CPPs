/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 20:29:12 by dsteiger          #+#    #+#             */
/*   Updated: 2025/11/04 17:25:10 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "../includes/AForm.hpp"
# include "../includes/Bureaucrat.hpp"
# include "../includes/PresidentialPardonForm.hpp"
# include "../includes/RobotomyRequestForm.hpp"
# include "../includes/ShrubberyCreationForm.hpp"
# include <cstdlib>
# include <ctime>
# include <iostream>
# include <math.h>
# include <string>

class Intern
{
    private:
        static std::string Names[3];
        static AForm* (*Constructors[3])(const std::string &target);

    public:
		Intern();
		Intern(const Intern& copy);
		~Intern();
		Intern &operator=(const Intern& copy);
        AForm *makeForm(std::string &formName, std::string &formTarget);
        class FormNotFoundException : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return "Form not found";
                }
        };
};

#endif