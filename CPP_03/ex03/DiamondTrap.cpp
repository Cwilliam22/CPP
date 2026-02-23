#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("DefaultDiamondTrap_clap_name"), ScavTrap("DefaultDiamondTrap"), FragTrap("DefaultDiamondTrap"), _name("DefaultDiamondTrap")
{
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(30);
	std::cout << "DiamondTrap " << _name << " is created (default)!" << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{ 
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(30);
	std::cout << "DiamondTrap " << _name << " is created!" << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name)
{
	std::cout << "DiamondTrap " << _name << " is copied!" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		ScavTrap::operator=(other);
		FragTrap::operator=(other);
		_name = other._name;
		std::cout << "DiamondTrap " << _name << " is assigned!" << std::endl;
	}
	return (*this);
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
