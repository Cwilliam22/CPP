#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static void printTitle(const std::string& title) {
	std::cout << "\n\033[36m--- " << title << " ---\033[0m" << std::endl;
}

int main(void) {
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

	// 2) Creation d'un ShrubberyCreationForm : grades fixes (sign 145, exec 137),
	printTitle("2. Creation d'un ShrubberyCreationForm");
	ShrubberyCreationForm shrubbery("garden");
	std::cout << shrubbery;

	// 3) Tenter d'executer un formulaire non signe via Bureaucrat::executeForm() :
	printTitle("3. Executer un formulaire non signe");
	boss.executeForm(shrubbery);

	// 4) Tenter de signer avec un grade insuffisant (145 requis pour signer).
	printTitle("4. Signature refusee (grade insuffisant)");
	Bureaucrat intern("Intern", 150);
	intern.signForm(shrubbery);
	std::cout << shrubbery;

	// 5) Signer avec un grade suffisant.
	printTitle("5. Signature reussie");
	boss.signForm(shrubbery);
	std::cout << shrubbery;

	// 6) Executer avec un grade insuffisant (137 requis pour executer) :
	printTitle("6. Execution refusee (grade insuffisant)");
	intern.executeForm(shrubbery);

	// 7) Executer avec un grade suffisant : l'action reelle doit se produire
	printTitle("7. Execution reussie (fichier genere)");
	boss.executeForm(shrubbery);

	// 8) Meme scenario, version courte, pour RobotomyRequestForm (resultat aleatoire).
	printTitle("8. RobotomyRequestForm : signature puis execution");
	RobotomyRequestForm robotomy("Bender");
	boss.signForm(robotomy);
	boss.executeForm(robotomy);

	// 9) Meme scenario, version courte, pour PresidentialPardonForm.
	printTitle("9. PresidentialPardonForm : signature puis execution");
	PresidentialPardonForm pardon("Bender");
	boss.signForm(pardon);
	boss.executeForm(pardon);

	return (0);
}
