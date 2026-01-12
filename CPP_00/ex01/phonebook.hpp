#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

class PhoneBook {

public: // ce qui doit être accessible de l'extérieur
	double x,y;
	double distance(const PhoneBook &P);
	PhoneBook milieu(const PhoneBook &P);

private: // ce qui ne doit pas être accessible de l'extérieur

};

#endif