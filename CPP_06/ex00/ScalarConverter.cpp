#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {

}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {

}

ScalarConverter::ScalarConverter& operator=(const ScalarConverter& other) {

}

ScalarConverter::~ScalarConverter() {

}

void ScalarConverter::convert() {

}

std::ostream &ScalarConverter::operator<<(std::ostream &os, ScalarConverter const &other)
{
	os << "ScalarConverter" << std::endl;
	return (os);
}
