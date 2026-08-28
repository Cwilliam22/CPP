#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>
#include <cctype>
#include <iostream>
#include <exception>

class ScalarConverter
{
	private:

	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();

		void convert();
};

std::ostream &operator<<(std::ostream & os, ScalarConverter const &other);

#endif