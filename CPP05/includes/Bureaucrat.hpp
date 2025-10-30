#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

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
        Bureaucrat(std::string &name, int grade);
        Bureaucrat(const Bureaucrat &copy);
	    Bureaucrat &operator=(const Bureaucrat &copy);
        ~Bureaucrat();
        std::string getName() const;
        int getGrade() const;
};


#endif