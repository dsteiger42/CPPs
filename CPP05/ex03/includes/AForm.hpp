/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 19:25:16 by dsteiger          #+#    #+#             */
/*   Updated: 2025/11/04 17:35:12 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
#include <math.h>
#include <ctime>
#include <cstdlib>
# include <string>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define RESET "\033[0m"

class	Bureaucrat;

class AForm
{
  private:
	const std::string _name;
	bool _isSigned;
	const int _gradeSign;
	const int _gradeExec;

  public:
	AForm();
	AForm(const std::string &name, int gradeSign, int gradeExec);
	AForm(const AForm &copy);
	AForm &operator=(const AForm &copy);
	virtual ~AForm();
	std::string getName() const;
	bool getSigned() const;
	int getGradeSign() const;
	int getGradeExec() const;
	void beSigned(const Bureaucrat &bureaucrat);
	virtual void execute(const Bureaucrat &executor) const = 0;

	class GradeTooHighException : public std::exception
	{
		public:
		const char *what() const throw()
		{
			return (GREEN "Grade is too high." RESET);
		}
	};

	class GradeTooLowException : public std::exception
	{
		public:
		const char *what() const throw()
		{
			return (GREEN "Grade is too low." RESET);
		}
	};

	class AlreadySignedException : public std::exception
	{
		public:
		const char *what() const throw()
		{
			return (GREEN " Form signed." RESET);
		}
	};

	class NotSignedException : public std::exception
	{
		public:
		const char *what() const throw()
		{
			return (GREEN "Formed not signed." RESET);
		}
	};
};
std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif