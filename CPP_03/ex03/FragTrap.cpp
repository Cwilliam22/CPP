#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("DefaultFragTrap")
{
    setHitPoints(100);
    setEnergyPoints(100);
    setAttackDamage(30);
    std::cout << "FragTrap " << getName() << " has been created (default)!" << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
	std::cout << "FragTrap " << getName() << " has been created!" << std::endl;
	return ;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "FragTrap " << getName() << " has been copied!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other); // Appel de l’opérateur d’affectation de la classe de base
        std::cout << "FragTrap " << getName() << " has been assigned!" << std::endl;
    }
    return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << getName() << " has been destroyed!" << std::endl;
	return ;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << getName() << " is asking for a high five!" << std::endl;
	return ;
}