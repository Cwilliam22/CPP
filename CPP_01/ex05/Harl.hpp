#ifndef HARL_HPP
#define HARL_HPP

#include <algorithm>
#include <string>
#include <cctype>

#include <iostream>
#include <fstream>

class Harl 
{
    private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);

    public:
	    Harl();
	    ~Harl();
        void complain(std::string level);


};

#endif