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

        // Setters
        void setHitPoints(int hp);
        void setEnergyPoints(int ep);
        void setAttackDamage(int ad);
        void setName(std::string name);

        // Getters
        std::string getName() const;
        int getHitPoints() const;
        int getEnergyPoints() const;
        int getAttackDamage() const;
};

#endif