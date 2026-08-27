#include "Bureaucrat.hpp"
#include "Form.hpp"

static void printTitle(const std::string& title)
{
	std::cout << std::endl << "\033[36m--- " << title << " ---\033[0m" << std::endl;
}

int main(void)
{
	// 1) Creation d'un Form avec des grades valides : aucune exception attendue.
	printTitle("1. Creation d'un Form valide");
	Form validForm("Permis de construire", 50, 25);
	std::cout << validForm;

	// 2) Creation d'un Form avec un grade trop bas en pouvoir (> 150).
	printTitle("2. Creation d'un Form avec un grade trop bas (> 150)");
	try
	{
		Form tooLow("Formulaire invalide", 1500, 1500);
		std::cout << tooLow;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception attendue : " << e.what() << std::endl;
	}

	// 3) Creation d'un Form avec un grade trop haut en pouvoir (< 1).
	printTitle("3. Creation d'un Form avec un grade trop haut (< 1)");
	try
	{
		Form tooHigh("Formulaire invalide", -10, -10);
		std::cout << tooHigh;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception attendue : " << e.what() << std::endl;
	}

	// 4) Signature reussie : le bureaucrate a un grade suffisant (<= grade requis).
	printTitle("4. Signature reussie (grade du bureaucrate suffisant)");
	Bureaucrat goodSigner("Alice", 20);
	Form form1("Congé exceptionnel", 50, 25);
	std::cout << "Avant signature : " << form1;
	goodSigner.signForm(form1);
	std::cout << "Apres signature : " << form1;

	// 5) Signature refusee : le bureaucrate n'a pas un grade suffisant.
	printTitle("5. Signature refusee (grade du bureaucrate insuffisant)");
	Bureaucrat weakSigner("Bernard", 100);
	Form form2("Demande de materiel", 50, 25);
	std::cout << "Avant tentative : " << form2;
	weakSigner.signForm(form2);
	std::cout << "Apres tentative : " << form2;

	// 6) Un Form deja signe reste signe si on retente avec un bureaucrate valide.
	printTitle("6. Nouvelle tentative apres une premiere signature reussie");
	goodSigner.signForm(form1);
	std::cout << "Toujours signe : " << form1;
	
	return (0);
}
