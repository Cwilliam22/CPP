#include "Fixed.hpp"

int main( void )
{
	///*
	// Main of the subject
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	//*/

	/*
	// My tests

	// // 6 comparison operators
	std::cout << "---------------- 6 comparison operators ---------------" << std::endl;
	Fixed a(10.5f);
	Fixed b(2.0f);
	Fixed c(5.0f);
	std::cout << "a" << " = " << a << "  "; // 10.5
	std::cout << "b" << " = " << b << "  "; // 2.0
	std::cout << "c" << " = " << c << std::endl << std::endl; // 5.0

	std::cout << "a > b" << " = " << (a > b) << std::endl; // 1
	std::cout << "a < b" << " = " << (a < b) << std::endl; // 0
	std::cout << "a >= b" << " = " << (a >= b) << std::endl; // 1
	std::cout << "a <= b" << " = " << (a <= b) << std::endl; // 0
	std::cout << "a == b" << " = " << (a == b) << std::endl; // 0
	std::cout << "a != b" << " = " << (a != b) << std::endl << std::endl; // 1

	// arithmetic operators
	std::cout << "---------------- 4 arithmetic operators ---------------" << std::endl;
	std::cout << "a" << " = " << a << "  "; // 10.5
	std::cout << "b" << " = " << b << "  "; // 2.0
	std::cout << "c" << " = " << c << std::endl << std::endl; // 5.0

	std::cout << "a / b" << " = " << a / b << std::endl; // 5.25
	std::cout << "a * b" << " = " << a * b << std::endl; // 21.0
	std::cout << "a + b" << " = " << a + b << std::endl; // 12.5
	std::cout << "a + c" << " = " << a + c << std::endl; // 15.5
	std::cout << "a - c" << " = " << a - c << std::endl << std::endl; // 5.5

	
	// 4 increment/decrement (pre-increment and post-increment, pre-decrement and post-decrement) operators
	std::cout << "------------- 4 increment/decrement operators ---------" << std::endl;
	std::cout << "a" << " = " << a << "  "; // 10.5
	std::cout << "b" << " = " << b << "  "; // 2.0
	std::cout << "c" << " = " << c << std::endl << std::endl; // 5.0

	std::cout << "a++" << " = " << a++ << std::endl; // 10.5
	std::cout << "a" << " = " << a << std::endl; //
	std::cout << "++a" << " = " << ++a << std::endl; // 12.5
	std::cout << "a" << " = " << a << std::endl; // 12.5
	std::cout << "a--" << " = " << a-- << std::endl; // 12.5
	std::cout << "a" << " = " << a << std::endl; // 11.5
	std::cout << "--a" << " = " << --a << std::endl; // 10.5
	std::cout << "a" << " = " << a << std::endl; // 10.5

	// overloaded functions (min and max)
	std::cout << "----------- overloaded functions (min and max) --------" << std::endl;
	std::cout << "a" << " = " << a << "  "; // 10.5
	std::cout << "b" << " = " << b << "  "; // 2.0
	std::cout << "c" << " = " << c << std::endl << std::endl; // 5.0

	std::cout << "min(a, b)" << " = " << Fixed::min(a, b) << std::endl; // 2.0
	std::cout << "min(a, c)" << " = " << Fixed::min(a, c) << std::endl; // 5.0
	std::cout << "max(a, b)" << " = " << Fixed::max(a, b) << std::endl; // 10.5
	std::cout << "max(a, c)" << " = " << Fixed::max(a, c) << std::endl; // 10.5

	*/
}

/*
Output (ex02):
0
0.00390625
0.00390625
0.00390625
0.0078125
10.1016
10.1016
*/