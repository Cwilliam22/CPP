#include "Fixed.hpp"

Fixed::Fixed()
{
    _fixedPointValue = 0;
    std::cout << "Default constructor called" << std::endl;
    return ;
}

Fixed::~Fixed()
{
    std::cout << "Default destructor called" << std::endl;
    return ;
}

Fixed::Fixed(const Fixed &src)
{
    std::cout << "Copy constructor called" << std::endl;
    this->_fixedPointValue = src.getRawBits();
    return ;
}

Fixed &Fixed::operator=(const Fixed &src)
{
    std::cout << "Copy assignment operator called" <<  std::endl;
    if (this != &src)
    {
        this->_fixedPointValue = src.getRawBits();
    }
    //std::cout << "Copy assignment operator called" <<  std::endl;
    return (*this);
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
    this->_fixedPointValue = raw;
    return ;
}
