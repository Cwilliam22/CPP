#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

class PhoneBook {

public: // ce qui doit être accessible de l'extérieur
	
	class Contact[8];
	int		nb_contact;

	PhoneBook(void); // constructeur
	-PhoneBook(void); // destructeur

	search_contact(void);
	add_contact(void);

private: // ce qui ne doit pas être accessible de l'extérieur

};

#endif