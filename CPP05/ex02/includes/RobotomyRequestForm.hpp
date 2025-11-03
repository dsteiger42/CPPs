#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"

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
		RobotomyRequestForm &operator=(const RobotomyRequestForm& other);
        void execute(Bureaucrat const &exec) const;
};
#endif
