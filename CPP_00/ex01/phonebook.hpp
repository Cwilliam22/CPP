#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <algorithm>
#include <iostream>
#include <string>
#include <cctype>

#include "contact.hpp"

class PhoneBook {

public:

	PhoneBook(void);
	~PhoneBook(void);

	int	search_contact(void);
	int	add_contact(void);
	int	exit_phonebook(void);
	int creating_contact(void);

	void    getContactDetails(int index);


	private:
	Contact contacts[8];
	int		nContact;
	int	 	nextIndex;

};

#endif