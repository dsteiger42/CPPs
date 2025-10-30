#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
    std::cout << "Default constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(std::string &name, int grade) : _name(name), _grade(grade)
{

}

// Initialize _name in the top, cuz I cant assign consts (_name = copy._name)
Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade)
{

}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{

}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor called." << std::endl;
}

std::string Bureaucrat::getName() const
{
    return this->_name;
}

int Bureaucrat::getGrade() const
{
    return this->_grade;
}

void Bureaucrat::incrementGrade(int amount)
{
    if ((_grade -= amount) < 1)
        throw;
        
}

void Bureaucrat::decreamentGrade(int amount)
{
    if ((_grade += amount) < 150)
        throw;
        
}

void Bureaucrat::decreamentGrade(int amount)
{
    
}