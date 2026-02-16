#ifndef FIXED_HPP
#define FIXED_HPP

#include <algorithm>
#include <string>
#include <cctype>

#include <iostream>
#include <fstream>

#include <cmath>

class Fixed 
{
	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;

	public:
		Fixed(); // Default constructor
		Fixed(const Fixed &src); // Copy constructor
		Fixed& operator=(const Fixed &src); // Copy assignment operator
		Fixed(const int intValue); // Int constructor
		Fixed(const float floatValue); // Float constructor
		~Fixed(); // Destructor

		int toInt(void) const;
		float toFloat(void) const;

		int getRawBits(void) const;
		void setRawBits(int const raw);

};

std::ostream& operator<<(std::ostream& os, const Fixed& f);


/*
And add the following function to the Fixed class files:
• An overload of the insertion («) operator that inserts a floating-point representation
of the fixed-point number into the output stream object passed as a parameter.
*/

#endif