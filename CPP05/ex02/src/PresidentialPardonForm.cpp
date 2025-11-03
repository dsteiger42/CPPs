#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{
    std::cout << "Default Presidential constructor called." << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(std::string target)
{
    std::cout << "Presidential constructor called." << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy)
{

}
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{

}
PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Presidential destructor called." << std::endl;
}



