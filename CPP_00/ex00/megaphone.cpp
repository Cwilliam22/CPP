#include <iostream>
#include <string>
#include <cctype>


int main(int argc, char** argv)
{
	std::string out;

	for (int j = 1; j < argc; ++j)
	{
		if (j > 1)
			out += ' ';
		for (int i = 0; argv[j][i]; i++)
			out += std::toupper(argv[j][i]);
	}
	std::cout << out << std::endl;
}
