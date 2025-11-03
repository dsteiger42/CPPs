#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeSign;
        const int _gradeExec;

    public:
        AForm();
        AForm(const std::string &name, bool isSigned, int gradeSign, int gradeExec);
        AForm(const AForm &copy);
	    AForm &operator=(const AForm &copy);
        ~AForm();
        std::string getName() const;
        bool getSigned() const;
        int getGradeSign() const;
        int getGradeExec() const;
        void beSigned(const Bureaucrat &bureaucrat);
        virtual void execute(Bureaucrat const &exec) const = 0;
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return GREEN "Bureaucrat form is too high." RESET;
                }
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return GREEN "Bureaucrat form is too low." RESET;
                }
        };
};
std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif