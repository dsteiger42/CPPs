/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 19:25:27 by dsteiger          #+#    #+#             */
/*   Updated: 2025/11/03 20:31:27 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include <iostream>
#include <math.h>
#include <ctime>
#include <cstdlib>
# include <string>

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"

class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;

    public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& copy);
		~RobotomyRequestForm();
		RobotomyRequestForm &operator=(const RobotomyRequestForm& copy);
        void beExecuted() const;
		void execute(const Bureaucrat &executor) const;
        static AForm* create(const std::string &target);
};
#endif
