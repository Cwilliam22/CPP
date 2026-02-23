#include "ScaveTrap.hpp"

ScaveTrap::ScaveTrap(std::string name) : ClapTrap(name)
{
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);
    std::cout << "Constructor called" << std::endl;
    std::cout << "ScaveTrap " << getName() << " is created!" << std::endl;
    return ;
}

ScaveTrap::~ScaveTrap()
{
    std::cout << "Destructor called" << std::endl;
    std::cout << "ScaveTrap " << getName() << " is destroyed!" << std::endl;
    return ;
}

void ScaveTrap::guardGate()
{
    std::cout << "ScaveTrap " << getName() << " is now in Gate keeper mode!" << std::endl;
    return ;
}