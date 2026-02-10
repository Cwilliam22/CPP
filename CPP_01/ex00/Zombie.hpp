#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <algorithm>
#include <iostream>
#include <string>
#include <cctype>


class Zombie {

public:

	Zombie(std::string name);
	~Zombie();

    // fonctions membres
    void announce(void);

private:
    std::string _name;

};

// fonctions non membres
Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif