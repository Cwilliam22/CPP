#include "Weapon.hpp"

Weapon::Weapon() : _type("") {
}

Weapon::Weapon(const std::string& type)
{
    _type = type;
    return ;
}

const std::string& Weapon::getType() const
{
    return (_type);
}
    
void Weapon::setType(const std::string& newType)
{
    _type = newType;
    return ;
}