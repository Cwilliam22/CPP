#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <algorithm>
#include <string>
#include <cctype>

#include <iostream>
#include <fstream>

#include <cmath>

class ClapTrap
{
	private:
		std::string         _name;
        int                 _hitPoints;
        int                 _energyPoints;
        int                 _attackDamage;

	public:
		ClapTrap(const std::string name);
		~ClapTrap();

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

};

#endif