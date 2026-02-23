#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name)
{
    std::cout << "DiamondTrap " << getName() << " is created!" << std::endl;
    return ;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << getName() << " is destroyed!" << std::endl;
    return ;
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap " << getName() << " is a DiamondTrap!" << std::endl;
    return ;
}