#include "../includes/harl.hpp"

void harlFilter::debug(void)
{
    std::cout << "[DEBUG]\n" << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl << std::endl;
}

void harlFilter::info(void)
{
    std::cout << "[INFO]\n" <<  "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}

void harlFilter::warning(void)
{
    std::cout <<  "[WARNING]\n" << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl << std::endl;
}

void harlFilter::error(void)
{
    std::cout <<  "[ERROR]\n" << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}

void harlFilter::complain(std::string level)
{
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    void (harlFilter::*functions[])() = {
        &harlFilter::debug,
        &harlFilter::info,
        &harlFilter::warning,
        &harlFilter::error
    };
    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i])
        {
            (this->*functions[i])();
            return;
        }
    }
}

int getLevel(std::string level)
{
    if (level == "DEBUG")
        return 0;
    if (level == "INFO")
        return 1;
    if (level == "WARNING")
        return 2;
    if (level == "ERROR")
        return 3;
    return -1;
}
