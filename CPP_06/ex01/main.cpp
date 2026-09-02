#include "Serializer.hpp"

static void printTitle(const std::string& title)
{
	std::cout << std::endl << "\033[36m--- " << title << " ---\033[0m" << std::endl;
}
 
int main(void)
{
	// 1) On cree un Data "non vide", avec un contenu concret a verifier.
	printTitle("1. Creation de l'objet Data d'origine");
	Data data;
	data.i = 42;
	data.f = 3.14f;
	data.d = 2.71828;
	data.c = 'A';
	std::cout << "Adresse d'origine : " << &data << std::endl;
	std::cout << "Contenu d'origine  : i=" << data.i << " f=" << data.f
	           << " d=" << data.d << " c=" << data.c << std::endl;
 
	// 2) serialize() : Data* -> uintptr_t
	printTitle("2. Serialisation (Data* -> uintptr_t)");
	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "Valeur serialisee (uintptr_t) : " << raw << std::endl;
 
	// 3) deserialize() : uintptr_t -> Data*
	printTitle("3. Deserialisation (uintptr_t -> Data*)");
	Data* deserialized = Serializer::deserialize(raw);
	std::cout << "Adresse deserialisee : " << deserialized << std::endl;
 
	// 4) La verification demandee par l'enonce : comparer les POINTEURS,
	printTitle("4. Verification : le pointeur deserialise == le pointeur d'origine ?");
	if (deserialized == &data)
		std::cout << "OK : les deux pointeurs sont identiques." << std::endl;
	else
		std::cout << "ERREUR : les pointeurs sont differents !" << std::endl;
 
	// 5) Bonus : on verifie aussi que le contenu pointe est bien intact.
	printTitle("5. Verification complementaire du contenu");
	std::cout << "Contenu via le pointeur deserialise : i=" << deserialized->i
	           << " f=" << deserialized->f << " d=" << deserialized->d
	           << " c=" << deserialized->c << std::endl;
 
	return (0);
}