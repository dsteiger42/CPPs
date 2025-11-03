#ifndef PRESIDENTALPARDONFORM_HPP
#define PRESIDENTALPARDONFORM_HPP

#include <iostream>
#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"

class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;

    public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& copy);
		~PresidentialPardonForm();
		PresidentialPardonForm &operator=(const PresidentialPardonForm& other);
        void execute(Bureaucrat const &exec) const;
};
#endif