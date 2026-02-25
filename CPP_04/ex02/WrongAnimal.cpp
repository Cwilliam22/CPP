#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("Animal")
{
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other._type)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	if (this != &other) {
		_type = other._type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal makes a wrong sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (_type);
}