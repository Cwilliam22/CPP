#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
    setHitPoints(100);
    setEnergyPoints(100);
    setAttackDamage(30);
    std::cout << "FragTrap " << getName() << " has been created!" << std::endl;
    return ;
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