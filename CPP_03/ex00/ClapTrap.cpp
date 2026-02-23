#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "Constructor called" << std::endl;
    std::cout << "ClapTrap " << _name << " is created!" << std::endl;
    return ;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
    std::cout << "ClapTrap " << _name << " is destroyed!" << std::endl;
    return ;
}

void ClapTrap::attack(const std::string& target)
{
    if (_energyPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " has no energy points left and cannot attack!" << std::endl;
        return ;
    }
    else if (_hitPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " is already dead and cannot attack!" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
    _energyPoints--;
    return ;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " is already dead and cannot take more damage!" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
    if (amount >= static_cast<unsigned int>(_hitPoints))
        _hitPoints = 0;
    else
        _hitPoints -= amount;
    return ;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_energyPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " has no energy points left and cannot repair itself!" << std::endl;
        return ;
    }
    else if (_hitPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " is already dead and cannot be repaired!" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << _name << " repairs itself, recovering " << amount << " hit points!" << std::endl;
    _energyPoints--;
    _hitPoints += amount;
    return ;
}