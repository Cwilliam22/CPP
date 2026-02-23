#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{ 
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(30);
	std::cout << "DiamondTrap " << _name << " is created!" << std::endl;
	return ;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << _name << " is destroyed!" << std::endl;
	return ;
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap " << _name << " is a DiamondTrap!" << std::endl;
	std::cout << "ClapTrap name is " << ClapTrap::getName() << "!" << std::endl;
	return ;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
	return ;
}
