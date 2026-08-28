#include "Bureaucrat.hpp"

static void printTitle(const std::string& title)
{
	std::cout << std::endl << "\033[36m--- " << title << " ---\033[0m" << std::endl;
}

int main(void)
{
	// 1) Creation avec un grade valide : ne doit lancer aucune exception.
	printTitle("1. Creation avec un grade valide");
	Bureaucrat valid("Gaspard", 50);
	std::cout << valid;

	// 2) Creation avec un grade trop bas en pouvoir (chiffre trop grand, > 150).
	printTitle("2. Creation avec un grade trop bas (> 150)");
	try
	{
		Bureaucrat tooLow("William", 1500);
		std::cout << tooLow << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception attendue : " << e.what() << std::endl;
	}

	// 3) Creation avec un grade trop haut en pouvoir (chiffre trop petit, < 1).
	printTitle("3. Creation avec un grade trop haut (< 1)");
	try
	{
		Bureaucrat tooHigh("Willsko", -10);
		std::cout << tooHigh << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception attendue : " << e.what() << std::endl;
	}

	// 4) incrementGrade() ameliore le grade (le chiffre baisse) jusqu'a la limite 1.
	printTitle("4. incrementGrade() jusqu'a la limite haute (grade 1)");
	Bureaucrat improving("Yosko", 2);
	std::cout << "Avant : " << improving << std::endl;
	improving.incrementGrade();
	std::cout << "Apres un incrementGrade() : " << improving << std::endl;
	try
	{
		improving.incrementGrade();
		std::cout << "Ceci ne devrait pas s'afficher" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception attendue : " << e.what() << std::endl;
	}

	// 5) decrementGrade() degrade le grade (le chiffre monte) jusqu'a la limite 150.
	printTitle("5. decrementGrade() jusqu'a la limite basse (grade 150)");
	Bureaucrat degrading("Bob", 149);
	std::cout << "Avant : " << degrading << std::endl;
	degrading.decrementGrade();
	std::cout << "Apres un decrementGrade() : " << degrading << std::endl;
	try
	{
		degrading.decrementGrade();
		std::cout << "Ceci ne devrait pas s'afficher" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception attendue : " << e.what() << std::endl;
	}

	// 6) Constructeur de copie : la copie doit avoir le meme nom et le meme grade.
	printTitle("6. Constructeur de copie");
	Bureaucrat original("Tim", 10);
	Bureaucrat copy(original);
	std::cout << "Original : " << original << std::endl;
	std::cout << "Copie    : " << copy;

	// 7) Operateur d'affectation : seul le grade doit changer, le nom reste le sien.
	printTitle("7. Operateur d'affectation (=)");
	Bureaucrat a("Alice", 5);
	Bureaucrat b("Bernard", 80);
	std::cout << "Avant  -> a : " << a << std::endl;
	std::cout << "Avant  -> b : " << b << std::endl;
	a = b;
	std::cout << "Apres a = b :" << std::endl;
	std::cout << "a (nom inchange, grade copie) : " << a << std::endl;
	std::cout << "b (inchange)                  : " << b << std::endl;

	return (0);
}
