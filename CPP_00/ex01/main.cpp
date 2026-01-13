#include "phonebook.hpp"
#include "contact.hpp"
#include <iostream>
#include <string>

int main(int argc, char** argv)
{
	class PhoneBook phonebook;
	class Contact contact;

	if (argc < 2)
	{
		std::cout << "Error: This program takes no arguments." << std::endl;
		return (1);
	}
	while (1)
	{
		std::cin >> argv[1];
		if (argv[1] == "EXIT")
			break ;
		else if (argv[1] == "ADD")
		{
			std::cout << "Adding a contact..." << std::endl;
		}
		else if (argv[1] == "SEARCH")
		{
			std::cout << "Searching contacts..." << std::endl;
		}
		else
			std::cout << "Unknown command." << std::endl;
	}
	return (0);
}