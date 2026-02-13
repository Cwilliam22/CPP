#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
        Fixed const _x;
        Fixed const _y;

	public:
		Point();
		Point(const float x, const float y);
        Point(const Point &src);
		Point& operator=(const Point &src);
		Point(const int intValue);
		Point(const float floatValue);
		~Point();
	
};

std::ostream& operator<<(std::ostream& os, const Point& p);

#endif