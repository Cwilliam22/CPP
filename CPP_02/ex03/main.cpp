#include "Point.hpp"

int main(void)
{
	// Points of the triangle
	Point a(0, 0);
	Point b(10, 0);
	Point c(5, 10);

	// Points to test
	// Inside the triangle
	Point point1(5, 5);
	Point point2(5, 3);
	Point point3(4, 4);

	// Outside the triangle
	Point point4(15, 5);
	Point point5(-1, 0);
	Point point6(5, 11);

	// On the edge of the triangle
	Point point7(5, 0);
	Point point8(2.5f, 5);
	Point point9(7.5f, 5);


	std::cout << "--------- TEST BSP ---------" << std::endl << std::endl;

	std::cout << "Inside the triangle:" << std::endl << std::endl;
	std::cout << "Point1 is " << (bsp(a, b, c, point1) ? "inside" : "outside") << " the triangle." << std::endl;
	std::cout << "Point2 is " << (bsp(a, b, c, point2) ? "inside" : "outside") << " the triangle." << std::endl;
	std::cout << "Point3 is " << (bsp(a, b, c, point3) ? "inside" : "outside") << " the triangle." << std::endl << std::endl;
	std::cout << "Outside the triangle:" << std::endl << std::endl;
	std::cout << "Point4 is " << (bsp(a, b, c, point4) ? "inside" : "outside") << " the triangle." << std::endl;
	std::cout << "Point5 is " << (bsp(a, b, c, point5) ? "inside" : "outside") << " the triangle." << std::endl;
	std::cout << "Point6 is " << (bsp(a, b, c, point6) ? "inside" : "outside") << " the triangle." << std::endl << std::endl;
	std::cout << "On the edge of the triangle:" << std::endl << std::endl;
	std::cout << "Point7 is " << (bsp(a, b, c, point7) ? "inside" : "outside") << " the triangle." << std::endl;
	std::cout << "Point8 is " << (bsp(a, b, c, point8) ? "inside" : "outside") << " the triangle." << std::endl;
	std::cout << "Point9 is " << (bsp(a, b, c, point9) ? "inside" : "outside") << " the triangle." << std::endl << std::endl;

	return (0);
}
