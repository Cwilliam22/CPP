#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

static void printTitle(const std::string& title) {
	std::cout << "\n\033[36m--- " << title << " ---\033[0m" << std::endl;
}

int main(void)
{
	// 1) Creation de Bureaucrat : rappel rapide des bornes de grade (1 a 150).
	printTitle("1. Creation de Bureaucrat (valide / trop haut / trop bas)");
	Bureaucrat boss("Boss", 1);
	std::cout << boss << std::endl;
	try
	{
		Bureaucrat invalid("Invalide", 0);
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception attendue : " << e.what() << std::endl;
	}

	Intern someRandomIntern;

	// 2) L'Intern cree un ShrubberyCreationForm a partir de son seul nom.
	printTitle("2. Intern cree un ShrubberyCreationForm");
	AForm* shrubbery = someRandomIntern.makeForm("shrubbery creation", "garden");
	if (shrubbery)
	{
		std::cout << *shrubbery;
		boss.signForm(*shrubbery);
		boss.executeForm(*shrubbery);
		delete shrubbery;
	}

	// 3) Meme scenario pour RobotomyRequestForm.
	printTitle("3. Intern cree un RobotomyRequestForm");
	AForm* robotomy = someRandomIntern.makeForm("robotomy request", "Bender");
	if (robotomy)
	{
		std::cout << *robotomy;
		boss.signForm(*robotomy);
		boss.executeForm(*robotomy);
		delete robotomy;
	}

	// 4) Meme scenario pour PresidentialPardonForm.
	printTitle("4. Intern cree un PresidentialPardonForm");
	AForm* pardon = someRandomIntern.makeForm("presidential pardon", "Bender");
	if (pardon)
	{
		std::cout << *pardon;
		boss.signForm(*pardon);
		boss.executeForm(*pardon);
		delete pardon;
	}

	// 5) Nom de formulaire inconnu : makeForm() doit afficher une erreur
	printTitle("5. Intern recoit un nom de formulaire invalide");
	AForm* unknown = someRandomIntern.makeForm("formulaire imaginaire", "personne");
	if (!unknown)
		std::cout << "Aucun formulaire cree, comme attendu." << std::endl;

	return (0);
}
