#include "ScalarConverter.hpp"

bool isNumber(const std::string& str) {
	size_t i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (i < str.length()) {
		if (!std::isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

void pseudoLitteraux(int type) {
	if (type == 1) 
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << "-inff" << std::endl;
		std::cout << "double: " << "-inf" << std::endl;
	}
	else if (type == 2)
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << "inff" << std::endl;
		std::cout << "double: " << "inf" << std::endl;
	}
	else if (type == 3)
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << "nanf" << std::endl;
		std::cout << "double: " << "nan" << std::endl;
	}
}

void printChar(const std::string& str, int type) {
	if (type == 1) 
	{
		std::cout << "char: " << "'" << str[1] << "'" << std::endl;
		return;
	}
	double valeur = strtol(str.c_str(), NULL, 10);
	if (str[0] == '-' || str[0] == '+')
		std::cout << "char: impossible" << std::endl;
	else if (valeur > std::numeric_limits<int>::max() || valeur < std::numeric_limits<int>::min())
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(valeur) && (valeur < 33 || valeur > 127))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << "'" << static_cast<char>(valeur) << "'" << std::endl;
}

void printInt(const std::string& str, int type) {
	if (type == 1) 
	{
		std::cout << "int: " << static_cast<int>(str[1]) << std::endl;
		return;
	}
	char* end;
	double valeur = strtol(str.c_str(), &end, 10);
	if (valeur > std::numeric_limits<int>::max() || valeur < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << valeur << std::endl;
}

void printFloat(const std::string& str, int type) {
	if (type == 1) 
	{
		std::cout << "float: " << static_cast<float>(str[1]) << ".0f" << std::endl;
		return;
	}
	char* end;
	float valeur = strtof(str.c_str(), &end);
	if (valeur == static_cast<int>(valeur))
		std::cout << "float: " << valeur << ".0f" << std::endl;
	else
		std::cout << "float: " << valeur << "f" << std::endl;
}

void printDouble(const std::string& str, int type) {
	if (type == 1) 
	{
		std::cout << "double: " << static_cast<double>(str[1]) << ".0" << std::endl;
		return;
	}
	char* end;
	double valeur = strtod(str.c_str(), &end);
	if (valeur == static_cast<int>(valeur))
		std::cout << "double: " << valeur << ".0" << std::endl;
	else
		std::cout << "double: " << valeur << std::endl;
}

void ScalarConverter::convert(const std::string& str) {

	int type = 0; // 0: unknown, 1: char, 2: int, 3: float, 4: double

	if ((str[0] == 39) && (str[2] == 39) && (str.length() == 3))
		type = 1;
	else if (str == "-inff" || str == "-inf")
	{
		pseudoLitteraux(1);
		return;
	}
	else if (str == "+inff" || str == "+inf")
	{
		pseudoLitteraux(2);
		return;
	}
	else if (str == "nanf" || str == "nan")
	{
		pseudoLitteraux(3);
		return;
	}
	else if (str.find('.') != std::string::npos)
	{
		if (str[str.length() - 1] == 'f')
			type = 3;
		else
			type = 4;
	}
	else if (isNumber(str))
		type = 2;
	else
	{
		std::cout << "Error: String not displayable." << std::endl;
		return;
	}

	printChar(str, type);
	printInt(str, type);
	printFloat(str, type);
	printDouble(str, type);
}

