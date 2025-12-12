/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:04:50 by dsteiger          #+#    #+#             */
/*   Updated: 2025/10/31 17:52:26 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

Form::Form() : _name("Default"), _isSigned(false), _gradeSign(150), _gradeExec(150)
{
	std::cout << "Default constructor called" << std::endl;
}

Form::Form(const std::string &name, bool isSigned, const int gradeSign,
	const int gradeExec) : _name(name), _isSigned(isSigned),
	_gradeSign(gradeSign), _gradeExec(gradeExec)
{
	std::cout << "Constructor called" << std::endl;
}

Form::Form(const Form &copy) : _name(copy._name), _isSigned(copy._isSigned),
	_gradeSign(copy._gradeSign), _gradeExec(copy._gradeExec)
{
}

Form &Form::operator=(const Form &copy)
{
    if (this != &copy)
		_isSigned = copy._isSigned;
	return (*this);
}

Form::~Form()
{
	std::cout << "Destructor called" << std::endl;
}

std::string Form::getName() const
{
	return (this->_name);
}

bool Form::getSigned() const
{
	return (this->_isSigned);
}

int Form::getGradeSign() const
{
	return (this->_gradeSign);
}

int Form::getGradeExec() const
{
	return (this->_gradeExec);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeSign)
        throw Form::GradeTooLowException();
    _isSigned = true;
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
    // this changes 0->false or 1->true in the final result
    out << std::boolalpha;
	out << "Form:\n" <<  "Name: " << form.getName() << "\nSigned: " << form.getSigned() << "\nGrade to sign: " << form.getGradeSign() << "\nGrade to execute: " << form.getGradeExec();
	return out;
}