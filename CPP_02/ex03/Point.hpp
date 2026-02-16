#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		Fixed const _x;
		Fixed const _y;

	public:
		Point(); // Default constructor
		Point(const float x, const float y); // Constructor with float parameters
		Point& operator=(const Point &src); // Copy assignment operator
		~Point(); // Destructor

		Fixed getX() const;
		Fixed getY() const;

};

bool bsp(Point const a, Point const b, Point const c, Point const point);
std::ostream& operator<<(std::ostream& os, const Point& p);

#endif