#include "phonebook.hpp"
#include "contact.hpp"

void    PhoneBook::getContactDetails(int index)
{
    std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
    std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
    return ;
}

void Contact::setContact(const std ::string fn, const std::string ln, const std::string nn, const std::string pn, const std::string ds)
{
    first_name = fn;
    last_name = ln;
    nickname = nn;
    phone_number = pn;
    darkest_secret = ds;
}

int PhoneBook::creating_contact()
{
    std::string fn;
    std::string ln;
    std::string nn;
    std::string pn;
    std::string ds;

    std::cout << "First name : " << std::endl;
    std::getline(std::cin, fn);
    std::cout << "Last name : " << std::endl;
    std::getline(std::cin, ln);
    std::cout << "Nickname : " << std::endl;
    std::getline(std::cin, nn);
    std::cout << "Phone number : " << std::endl;
    std::getline(std::cin, pn);
    std::cout << "Darkest secret : " << std::endl;
    std::getline(std::cin, ds);

    if (fn.empty() || ln.empty() || nn.empty() || pn.empty() || ds.empty())
    {
        std::cout << "Error: Empty field(s). Contact not created." << std::endl;
        return (2);
    }
    else if (!std::all_of(pn.begin(), pn.end(), ::isdigit))
    {
        std::cout << "Error: Phone number must contain only digits. Contact not created." << std::endl;
        return (2);
    }
    contacts[nextIndex].setContact(fn, ln, nn, pn, ds);
    nextIndex = (nextIndex + 1) % 8;
    if (this->nContact < 8)
        this->nContact++;
    std::cout << "Contact created successfully!" << std::endl;
    return (1);
}
