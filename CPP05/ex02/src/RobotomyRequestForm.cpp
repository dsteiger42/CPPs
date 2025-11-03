#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{
    std::cout << "Default Robotomy constructor called." << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(std::string target)
{
    std::cout << "Robotomy constructor called." << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy)
{

}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{

}
RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Robotomy destructor called." << std::endl;
}