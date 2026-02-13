#include "Point.hpp"

Point::Point() : _x(0), _y(0) {
}

Point::Point(const float x, const float y) : _x(x), _y(y) {
}

Point::~Point() {
}

Point &Point::operator=(const Point &src)
{
	if (this != &src)
	{
		this->_x._fixedPointValue = src._x._fixedPointValue;
		this->_y._fixedPointValue = src._y._fixedPointValue;
	}
	return (*this);
}