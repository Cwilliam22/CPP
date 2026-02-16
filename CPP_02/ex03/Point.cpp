#include "Point.hpp"

Point::Point() : _x(0), _y(0) {
}

Point::Point(const float x, const float y) : _x(x), _y(y) {
}

Point::~Point() {
}

Point &Point::operator=(const Point &src)
{
	(void)src;
	return (*this);
}

Fixed Point::getX() const {
	return (this->_x);
}

Fixed Point::getY() const {
	return (this->_y);
}