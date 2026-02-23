#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("DefaultScavTrap")
{
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);
    std::cout << "ScavTrap " << getName() << " is created!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);
    std::cout << "ScavTrap " << getName() << " is created!" << std::endl;
    return ;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "ScavTrap " << getName() << " is copied!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other); // Appel de l'opérateur d'affectation de la classe de base
        std::cout << "ScavTrap " << getName() << " is assigned!" << std::endl;
    }
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << getName() << " is destroyed!" << std::endl;
    return ;
}

void ScavTrap::attack(const std::string& target) {
	if (getHitPoints() == 0) {
		std::cout << "ScavTrap " << getName() << " is dead and cannot attack!" << std::endl;
		return;
	}
	if (getEnergyPoints() == 0) {
		std::cout << "ScavTrap " << getName() << " has no energy to attack!" << std::endl;
		return;
	}
    setEnergyPoints(getEnergyPoints() - 1);
	std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << getName() << " is now in Gate keeper mode!" << std::endl;
    return ;
}