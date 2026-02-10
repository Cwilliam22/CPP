#include "phonebook.hpp"
#include "contact.hpp"

std::string Contact::getFirstName()
{
    return this->first_name;
}

std::string Contact::getLastName()
{
    return this->last_name;
}

std::string Contact::getNickname()
{
    return this->nickname;
}

std::string Contact::getPhoneNumber()
{
    return this->phone_number;
}

std::string Contact::getDarkestSecret()
{
    return this->darkest_secret;
}

int PhoneBook::search_contact(void)
{
    std::cout << "Searching contacts..." << std::endl;
    if (nContact == 0)
    {
        std::cout << "PhoneBook is empty" << std::endl;
        return (1);
    }
    std::cout << "|  Index   |First Name| Last Name| Nickname |" << std::endl;
    for (int i = 0; i < nContact; i++)
    {
        std::cout << "|";
        std::cout.width(10);
        std::cout << i << "|";
        std::string fn = contacts[i].getFirstName();
        std::string ln = contacts[i].getLastName();
        std::string nn = contacts[i].getNickname();

        if (fn.length() > 10)
            fn = fn.substr(0, 9) + ".";
        if (ln.length() > 10)
            ln = ln.substr(0, 9) + ".";
        if (nn.length() > 10)
            nn = nn.substr(0, 9) + ".";

        std::cout.width(10);
        std::cout << fn << "|";
        std::cout.width(10);
        std::cout << ln << "|";
        std::cout.width(10);
        std::cout << nn << "|" << std::endl;
    }
    int flag = 0;
    int idx = -1;
    while (flag == 0)
    {
        std::cout << "Enter the index of the contact to view details: " << std::endl;
        std::string index;
        std::getline(std::cin, index);
        if (index.empty() || !std::all_of(index.begin(), index.end(), ::isdigit))
        {
            std::cout << "Invalid index." << std::endl;
            continue;
        }
        idx = std::stoi(index);
        if (idx < 0 || idx >= nContact)
        {
            std::cout << "Invalid index." << std::endl;
            continue;
        }
        flag = 1;
    }
    if (idx == -1)
        return (0);
    getContactDetails(idx);
    return (1);
}

int PhoneBook::add_contact(void)
{
    std::cout << "Adding a contact..." << std::endl;
    if (creating_contact() == 2)
        return (1);
    return (1);
}

int PhoneBook::exit_phonebook(void)
{
    std::cout << "Exiting PhoneBook. Goodbye!" << std::endl;
    return (1);
}
