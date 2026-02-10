#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <algorithm>
#include <iostream>
#include <string>
#include <cctype>

class Zombie {

public:

	Zombie(void);
	~Zombie();

    void announce(void);
    void setName(std::string name);

private:
    std::string _name;

};

Zombie* zombieHorde(int N, std::string name);

#endif