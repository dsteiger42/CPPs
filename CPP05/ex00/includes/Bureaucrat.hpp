#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"


/*
&name -> is done by reference to avoid copying what could be a long string.
grade -> is faster to just do a copy since its just 4 bytes.
*/

//Nested classes are used to define exceptions specific to a class.

class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;

    public:
        Bureaucrat();
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat &copy);
	    Bureaucrat &operator=(const Bureaucrat &copy);
        ~Bureaucrat();
        std::string getName() const;
        int getGrade() const;
        void setGrade(int amount);
        void incrementGrade(int amount);
        void decreamentGrade(int amount);

        // exception = base class for all exceptions
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return RED "Bureaucrat grade is too high." RESET;
                }
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return RED "Bureaucrat grade is too low." RESET;
                }
        };
};
#endif