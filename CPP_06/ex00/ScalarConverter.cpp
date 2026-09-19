#include "ScalarConverter.hpp"

bool isFullyConsumed(const std::string& str)
{
    char* end;
    strtod(str.c_str(), &end);
    return (*end == '\0' && end != str.c_str());
}

bool isNumber(const std::string& str) {
	size_t i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str.length() == 1)
			return (false);
		i++;
	}
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

void printChar(const double valeur) {
	if (valeur > std::numeric_limits<int>::max() || valeur < std::numeric_limits<int>::min())
		std::cout << "char: impossible" << std::endl;
	else if (valeur < 0 || valeur > 127 || !std::isprint(static_cast<int>(valeur)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(valeur) << "'" << std::endl;
}

void printInt(const double valeur) {
	if (valeur > std::numeric_limits<int>::max() || valeur < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(valeur) << std::endl;
}

void printFloat(const double valeur) {
	float f = static_cast<float>(valeur);
	if (f == std::floor(f))
    	std::cout << "float: " << f << ".0f" << std::endl;
	else
    	std::cout << "float: " << f << "f" << std::endl;
}

void printDouble(const double valeur) {
	if (valeur == std::floor(valeur))
		std::cout << "double: " << valeur << ".0" << std::endl;
	else
		std::cout << "double: " << valeur << std::endl;
}

void ScalarConverter::convert(const std::string& str) {

	//int type = 0; // char->1, int->2, float->3, double->4
	double valeur = 0;

	if ((str[0] == 39) && (str.length() == 3) && (str[2] == 39))
	{
		//type = 1;
		valeur = static_cast<double>(str[1]);
	}
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
		{
			if (!isFullyConsumed(str.substr(0, str.length() - 1)))
			{
				std::cout << "Error: String not displayable." << std::endl;
				return;
			}
			//type = 3;
			valeur = strtof(str.c_str(), NULL);
		}
		else
		{
			if (!isFullyConsumed(str))
			{ 
				std::cout << "Error: String not displayable." << std::endl;
				return;
			}
			//type = 4;
			valeur = strtod(str.c_str(), NULL);
		}
	}
	else if (isNumber(str))
	{
		//type = 2;
		valeur = strtol(str.c_str(), NULL, 10);
	}
	else
	{
		std::cout << "Error: String not displayable." << std::endl;
		return;
	}

	printChar(valeur);
	printInt(valeur);
	printFloat(valeur);
	printDouble(valeur);
}
