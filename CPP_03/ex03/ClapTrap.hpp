#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
	private:
		std::string         _name;
        int                 _hitPoints;
        int                 _energyPoints;
        int                 _attackDamage;

	public:
        ClapTrap(); // Default constructor
        ClapTrap(std::string name); // Initialisation Constructor
        ClapTrap(const ClapTrap& other); // Copy constructor
        ClapTrap& operator=(const ClapTrap& other); // Copy assignment operator
		~ClapTrap(); // Destructor

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