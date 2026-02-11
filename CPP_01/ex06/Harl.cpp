#include "Harl.hpp"

Harl::Harl()
{
    //std::cout << "Harl constructor called" << std::endl;
    return ;
}

Harl::~Harl()
{
    //std::cout << "Harl destructor called" << std::endl;
    return ;
}

void Harl::debug(void)
{
    std::cout << "[DEBUG]" << std::endl << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl << "I really do!" << std::endl << std::endl;
    return ;
}

void Harl::info(void)
{
    std::cout << "[INFO]" << std::endl << "I cannot believe adding extra bacon costs more money." << std::endl << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
    return ;
}

void Harl::warning(void)
{
    std::cout << "[WARNING]" << std::endl <<  "I think I deserve to have some extra bacon for free." << std::endl << "I’ve been coming for years, whereas you started working here just last month." << std::endl << std::endl;
    return ;
}

void Harl::error(void)
{
    std::cout << "[ERROR]" << std::endl << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
    return ;
}

void Harl::complain(std::string level)
{
    int lvl = 0;

    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; i++)
    {
        lvl = (level == levels[i]) ? i + 1 : lvl;
    }
    switch (lvl)
    {
        case 1:
            debug();
        case 2:
            info();
        case 3:
            warning();
        case 4:
            error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
    }
    return ;
}

