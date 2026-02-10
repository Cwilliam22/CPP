#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    _fixedPointValue = 0;
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

Fixed::Fixed(const int intValue)
{
    std::cout << "Int constructor called" << std::endl;
    this->_fixedPointValue = intValue << _fractionalBits;
    return ;
}

// 1 << _fractionalBits = 256 -> générique et évite les erreurs -> évite les incohérences quand fractionalBits change
// floatValue * 256 et arrondi à l'entier le plus proche
Fixed::Fixed(const float floatValue)
{
    std::cout << "Float constructor called" << std::endl;
    this->_fixedPointValue = roundf(floatValue * (1 << _fractionalBits));
    return ;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

int Fixed::getRawBits(void) const
{
    //std::cout << "getRawBits member function called" << std::endl;
    return (this->_fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
    this->_fixedPointValue = raw;
    return ;
}

int Fixed::toInt(void) const
{
    return (this->_fixedPointValue >> _fractionalBits);
}

float Fixed::toFloat(void) const
{
    return (this->_fixedPointValue / static_cast<float>(1 << _fractionalBits));
}

// 6 comparison operators
//  opérateur (>)
bool Fixed::operator>(const Fixed& obj) const {
    return this->_fixedPointValue > obj._fixedPointValue;
}

//  opérateur (<)
bool Fixed::operator<(const Fixed& obj) const {
    return this->_fixedPointValue < obj._fixedPointValue;
}

//  opérateur (>=)
bool Fixed::operator>=(const Fixed& obj) const {
    return this->_fixedPointValue >= obj._fixedPointValue;
}

//  opérateur (<=)
bool Fixed::operator<=(const Fixed& obj) const {
    return this->_fixedPointValue <= obj._fixedPointValue;
}

//  opérateur (==)
bool Fixed::operator==(const Fixed& obj) const {
    return this->_fixedPointValue == obj._fixedPointValue;
}

//  opérateur (!=)
bool Fixed::operator!=(const Fixed& obj) const {
    return this->_fixedPointValue != obj._fixedPointValue;
}

// 4 arithmetic operators
// opérateur (+)
Fixed &Fixed::operator+(const Fixed& obj) {
    Fixed result;
    result.setRawBits(this->_fixedPointValue + obj._fixedPointValue);
    return (result);
}

// opérateur (-)
Fixed &Fixed::operator-(const Fixed& obj) {
    Fixed result;
    result.setRawBits(this->_fixedPointValue - obj._fixedPointValue);
    return (result);
}

// opérateur (*)
Fixed &Fixed::operator*(const Fixed& obj) {
    Fixed result;
    result.setRawBits(this->_fixedPointValue * obj._fixedPointValue);
    return (result);
}

// opérateur (/)
Fixed &Fixed::operator/(const Fixed& obj) {
    Fixed result;
    result.setRawBits(this->_fixedPointValue / obj._fixedPointValue);
    return (result);
}

// 4 increment/decrement (pre-increment and post-increment, pre-decrement and post-decrement) operators

// opérateur (++)
Fixed &Fixed::operator++(const Fixed& obj) {
    Fixed result;
    return (result);
}

// opérateur (--)
Fixed &Fixed::operator--(const Fixed& obj) {
    Fixed result;
    return (result);
}
Fixed &Fixed::operator/(const Fixed& obj) {
    Fixed result;
    result.setRawBits(this->_fixedPointValue / obj._fixedPointValue);
    return (result);
}
Fixed &Fixed::operator/(const Fixed& obj) {
    Fixed result;
    result.setRawBits(this->_fixedPointValue / obj._fixedPointValue);
    return (result);
}


// if (value > MAX) value = MAX;
// if (value < MIN) value = MIN;
