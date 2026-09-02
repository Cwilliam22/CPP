#include "ScalarConverter.hpp"

/*
static void printTitle(const std::string& title)
{
	std::cout << std::endl << "\033[36m--- " << title << " ---\033[0m" << std::endl;
}
 
int main(void)
{
	// 1) Un entier "normal" : toutes les conversions doivent etre valides.
	printTitle("1. Int valide (42)");
	ScalarConverter::convert("42");
 
	// 2) Un entier negatif : verifie la gestion du signe.
	printTitle("2. Int negatif (-42)");
	ScalarConverter::convert("-42");
 
	// 3) Un float valide : verifie le suffixe 'f' et le cast en char ('*').
	printTitle("3. Float valide (42.0f)");
	ScalarConverter::convert("42.0f");
 
	// 4) Un double valide.
	printTitle("4. Double valide (42.0)");
	ScalarConverter::convert("42.0");
 
	// 5) Un char litteral valide.
	printTitle("5. Char litteral valide ('a')");
	ScalarConverter::convert("'a'");
 
	// 6) Le cas 0 : le char correspondant (NUL) n'est pas affichable.
	printTitle("6. Cas particulier : 0 (char non affichable)");
	ScalarConverter::convert("0");
 
	// 7) Les pseudo-litteraux double.
	printTitle("7. Pseudo-litteraux double (nan / +inf / -inf)");
	ScalarConverter::convert("nan");
	ScalarConverter::convert("+inf");
	ScalarConverter::convert("-inf");
 
	// 8) Les pseudo-litteraux float.
	printTitle("8. Pseudo-litteraux float (nanf / +inff / -inff)");
	ScalarConverter::convert("nanf");
	ScalarConverter::convert("+inff");
	ScalarConverter::convert("-inff");
 
	// 9) Overflow : une valeur trop grande pour tenir dans un int.
	printTitle("9. Overflow int (2147483648)");
	ScalarConverter::convert("2147483648");
 
	// 10) Une entree invalide : ne correspond a aucun format de litteral connu.
	printTitle("10. Entree invalide (abc)");
	ScalarConverter::convert("abc");
 
	return (0);
}
*/

int main(int argc, char** argv)
{
	// Mode 1 : usage classique de l'exercice -> ./convert <litteral>
	if (argc == 2)
	{
		ScalarConverter::convert(argv[1]);
		return (0);
	}
 
	// Mode 2 : lance sans argument -> boucle infinie de test interactif,
	if (argc == 1)
	{
		std::cout << "Mode interactif (Ctrl+D pour quitter)" << std::endl;
		while (1)
		{
			std::cout << "\033[36m> \033[0m";
			std::string input;
			if (!std::getline(std::cin, input))
			{
				std::cout << std::endl;
				break;
			}
			if (input.empty())
				continue;
			ScalarConverter::convert(input);
		}
		return (0);
	}
 
	std::cout << "Usage: " << argv[0] << " <literal>" << std::endl;
	return (1);
}