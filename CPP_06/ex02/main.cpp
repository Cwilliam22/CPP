#include "Base.hpp"

static void printTitle(const std::string& title)
{
	std::cout << std::endl << "\033[36m--- " << title << " ---\033[0m" << std::endl;
}
 
int main(void)
{
	// srand() : une seule fois, au tout debut du programme.
	srand(static_cast<unsigned int>(time(NULL)));
 
	const int nbTests = 10;
 
	printTitle("Test de identify(Base*)");
	for (int i = 0; i < nbTests; ++i)
	{
		Base* basePtr = generate();
		std::cout << "Tirage " << i << " -> ";
		identify(basePtr);
		delete basePtr;
	}
 
	printTitle("Test de identify(Base&)");
	for (int i = 0; i < nbTests; ++i)
	{
		Base* basePtr = generate();
		std::cout << "Tirage " << i << " -> ";
		identify(*basePtr);
		delete basePtr;
	}
 
	return (0);
}
 