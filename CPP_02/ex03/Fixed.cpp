#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0) {
}

Fixed::Fixed(const Fixed &src) : _fixedPointValue(src.getRawBits()) {
}

Fixed &Fixed::operator=(const Fixed &src)
{
	if (this != &src)
	{
		this->_fixedPointValue = src.getRawBits();
	}
	return (*this);
}

Fixed::Fixed(const int intValue) : _fixedPointValue(intValue << _fractionalBits) {
}

// 1 << _fractionalBits = 256 -> générique et évite les erreurs -> évite les incohérences quand fractionalBits change
// floatValue * 256 et arrondi à l'entier le plus proche
Fixed::Fixed(const float floatValue) : _fixedPointValue(roundf(floatValue * (1 << _fractionalBits))) {
}

Fixed::~Fixed() {
}

int Fixed::getRawBits(void) const {
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
Fixed Fixed::operator+(const Fixed& obj) const {
	Fixed result;
	result.setRawBits(this->_fixedPointValue + obj._fixedPointValue);
	return (result);
}

// opérateur (-)
Fixed Fixed::operator-(const Fixed& obj) const {
	Fixed result;
	result.setRawBits(this->_fixedPointValue - obj._fixedPointValue);
	return (result);
}

// opérateur (*)
Fixed Fixed::operator*(const Fixed& obj) const {
	Fixed result;
	result.setRawBits((this->_fixedPointValue * obj._fixedPointValue) >> _fractionalBits);
	return (result);
}

// opérateur (/)
Fixed Fixed::operator/(const Fixed& obj) const {
	Fixed result;
	result.setRawBits((this->_fixedPointValue << _fractionalBits) / obj._fixedPointValue);
	return (result);
}

// 4 increment/decrement (pre-increment and post-increment, pre-decrement and post-decrement) operators

// opérateur post (++)
Fixed Fixed::operator++(int) {
	Fixed old = *this;
	this->_fixedPointValue += 1;
	//this->_fixedPointValue +=  (1 << _fractionalBits);
	return (old);
}

// opérateur pre (++)
Fixed &Fixed::operator++() {
	this->_fixedPointValue += 1;
	//this->_fixedPointValue +=  (1 << _fractionalBits);
	return (*this);
}

// opérateur post (--)
Fixed Fixed::operator--(int) {
	Fixed old = *this;
	this->_fixedPointValue -= 1;
	//this->_fixedPointValue -=  (1 << _fractionalBits);
	return (old);
}

// opérateur pre (--)
Fixed &Fixed::operator--() {
	this->_fixedPointValue -= 1;
	//this->_fixedPointValue -=  (1 << _fractionalBits);
	return (*this);
}

// overloaded functions (min and max)

Fixed& Fixed::min(Fixed& obj1, Fixed& obj2)
{
	if (obj1 < obj2)
		return (obj1);
	else
		return (obj2);
}
const Fixed& Fixed::min(const Fixed& obj1, const Fixed& obj2)
{
	if (obj1 < obj2)
		return (obj1);
	else
		return (obj2);
}

Fixed& Fixed::max(Fixed& obj1, Fixed& obj2)
{
	if (obj1 > obj2)
		return (obj1);
	else
		return (obj2);
}

const Fixed& Fixed::max(const Fixed& obj1, const Fixed& obj2)
{
	if (obj1 > obj2)
		return (obj1);
	else
		return (obj2);
}

std::ostream& operator<<(std::ostream& os, const Fixed& f) {
	os << f.toFloat();   // affiche le Fixed comme un float
	return os;
}
