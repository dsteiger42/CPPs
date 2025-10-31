/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:04:45 by dsteiger          #+#    #+#             */
/*   Updated: 2025/10/31 17:41:03 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"

class Form
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeSign;
        const int _gradeExec;

    public:
        Form();
        Form(const std::string &name, bool isSigned, int gradeSign, int gradeExec);
        Form(const Form &copy);
	    Form &operator=(const Form &copy);
        ~Form();
        std::string getName() const;
        bool getSigned() const;
        int getGradeSign() const;
        int getGradeExec() const;
        class FormTooHighException : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return GREEN "Bureaucrat form is too high." RESET;
                }
        };

        class FormTooLowException : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return GREEN "Bureaucrat form is too low." RESET;
                }
        };



};

#endif