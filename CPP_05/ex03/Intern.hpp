#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <cctype>
#include <iostream>
#include <exception>

class AForm;

class Intern
{
	private:

	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();

        // MakeForm methods
        AForm* createShrubbery(const std::string& target) const;
        AForm* createRobotomy(const std::string& target) const;
        AForm* createPresidentialPardon(const std::string& target) const;

        AForm* makeForm(std::string formName, std::string target) const;
};

std::ostream &operator<<(std::ostream & os, Intern const &other);

#endif