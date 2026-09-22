#include "BitcoinExchange.hpp"


bool InvalidDate(std::string date) {
    
    return (true);
}

bool InvalidValue(std::string value) {
    if ()
    return (true);
}

bool lineCheck(std::string line) {
    size_t pos = line.find("|");

    if (pos == std::string::npos)
    {
        std::cout << "Error: line is in the wrong format." << std::endl;
        return (1);
    }
    std::string date = line.substr(0, pos);
    std::cout << date << std::endl;
    std::string value  = line.substr(pos + 2);
    std::cout << value << std::endl;

    if (!InvalidDate(date))
        return (false);
    else if (!InvalidValue(value))
        return (false);
    else
        return (true);
}