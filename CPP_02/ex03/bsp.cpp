#include "Point.hpp"
#include "Fixed.hpp"

static Fixed area_is_positive(Point const p1, Point const p2, Point const p3)
{
	return (p1.getX().toFloat() * (p2.getY().toFloat() - p3.getY().toFloat()) +
			p2.getX().toFloat() * (p3.getY().toFloat() - p1.getY().toFloat()) +
			p3.getX().toFloat() * (p1.getY().toFloat() - p2.getY().toFloat()));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	// Calculate the area
	Fixed area_a = area_is_positive(a, b, point);
	Fixed area_b = area_is_positive(b, c, point);
	Fixed area_c = area_is_positive(c, a, point);

	if (area_a < 0 && area_b < 0 && area_c < 0)
		return (true);
	if (area_a > 0 && area_b > 0 && area_c > 0)
		return (true);
	if (area_a == 0 || area_b == 0 || area_c == 0)
		return (false);
	return (false);
}