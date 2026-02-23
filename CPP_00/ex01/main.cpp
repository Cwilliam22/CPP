#include "phonebook.hpp"
#include "contact.hpp"
#include <iostream>
#include <string>


PhoneBook::PhoneBook(void)
{
		// action du constructeur
		std::cout << "CONSTRUCTEUR !!!" << std::endl;
		this->nContact = 0;
		this->nextIndex = 0;
		return ;
}

PhoneBook::~PhoneBook(void)
{
		// action du destructeur
		std::cout << "DESTRUCTEUR !!!" << std::endl;
		return ;
}

int main(int argc, char** argv)
{
	class PhoneBook phonebook;
	class Contact contact;
	std::string command;

	(void)argv;
	if (argc > 2)
	{
		std::cout << "Error: This program takes no arguments." << std::endl;
		return (1);
	}
	std::cout << "=========My Awesome PhoneBook========" << std::endl;
	std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;
	std::cout << "=====================================" << std::endl;
	while (1) // tant que pas Ctrl + D
	{
		std::cout << std::endl << "Enter a command : " << std::endl;
		std::getline(std::cin, command);
		if (command == "EXIT")
			break ;
		else if (command == "ADD")
		{
			if (!phonebook.add_contact())
				return (1);
		}
		else if (command == "SEARCH")
		{
			if (!phonebook.search_contact())
				return (1);
		}
		else
			std::cout << "Unknown command." << std::endl;
	}
	return (0);
}