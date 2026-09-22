#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    std::ifstream file(argv[1]);
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return (1);
    }
    if (argc != 2)
    {
        return (1);
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
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
    }
    return (0);
}


// Format data:
// 2022-03-29,47115.93

// Format input
// 2011-01-03 | 2