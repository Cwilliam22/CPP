#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern&) {}

Intern& Intern::operator=(const Intern&) {
    return *this;
}

Intern::~Intern() {}

AForm* Intern::createShrubbery(const std::string& target) const{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::createRobotomy(const std::string& target) const {
	return (new RobotomyRequestForm(target));
}

AForm* Intern::createPresidentialPardon(const std::string& target) const {
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(std::string formName, std::string target) const {
    std::string Names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm*    (Intern::*funcs[3])(const std::string&) const = {&Intern::createShrubbery, &Intern::createRobotomy, &Intern::createPresidentialPardon};
    for (int i = 0; i < 3; i++)
    {
        if (formName == Names[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*funcs[i])(target);
        }
    }
    std::cout << "Intern does not create " << formName << std::endl;
    return (0);
}
