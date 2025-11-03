#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{
    std::cout << "Default Shrubbery constructor called." << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
{
    std::cout << "Shrubbery constructor called." << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy)
{

}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{

}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Shrubbery destructor called." << std::endl;
}