#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int main(void)
{
    // this object was never fully constructed, so destructor is not called
    try
    {
        Bureaucrat bur1("Bur1", 200);
    }
    catch(const std::exception &e)
    {
        std::cerr << "1st case exception. Too low.\n" << e.what() << std::endl;
    }

    std::cout << "\n-------------------\n" << std::endl;

    try
    {
        Bureaucrat bur1("Bur1", 0);
    }
    catch(const std::exception &e)
    {
        std::cerr << "2st case exception. Too high.\n" << e.what() << std::endl;
    }

    std::cout << "\n-------------------\n" << std::endl;

    try
    {
        Bureaucrat bur2("Bur2", 130);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n-------------------\n" << std::endl;

    // multiple exceptions
    try
    {
        Bureaucrat bur3("Bur3", -1);
    }
    catch(const Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << "Error: Grade too high\n" << e.what() << std::endl;
    }
    catch(const Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << "Error: Grade too low\n" << e.what() << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << "Error: Default exception\n" << e.what() << std::endl;
    }

    std::cout << "\n-------------------\n" << std::endl;



    std::cout << "\n-------------------\n" << std::endl;
}