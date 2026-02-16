#ifndef FIXED_HPP
#define FIXED_HPP

#include <algorithm>
#include <string>
#include <cctype>

#include <iostream>
#include <fstream>

class Fixed 
{
	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;

	public:
		Fixed(); // Default constructor
		Fixed(const Fixed &src); // Copy constructor
		Fixed& operator=(const Fixed &src); // Copy assignment operator
		~Fixed(); // Destructor

		int getRawBits(void) const;
		void setRawBits(int const raw);

};

#endif