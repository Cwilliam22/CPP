#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>
#include <cctype>
#include <iostream>
#include <exception>
#include <limits>
#include <cstdlib>
#include <iomanip>
#include <cmath>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();

	public:
		static void convert(const std::string& str) ;
};

#endif