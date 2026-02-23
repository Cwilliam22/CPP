#include "ClapTrap.hpp"

int main(void)
{
	std::cout << "===Création de ClapTrap 'Clap'===" << std::endl;
	ClapTrap c("Clap");

	std::cout << std::endl << "===Affichage des attributs initiaux===" << std::endl;
	std::cout << "Nom : " << c.getName() << std::endl;
	std::cout << "Points de vie : " << c.getHitPoints() << std::endl;
	std::cout << "Points d'énergie : " << c.getEnergyPoints() << std::endl;
	std::cout << "Dégâts d'attaque : " << c.getAttackDamage() << std::endl;

	std::cout << std::endl << "===Actions===" << std::endl;
	std::cout << "Appel de attack('ennemi')" << std::endl;
	c.attack("ennemi");
	std::cout << "Appel de takeDamage(3)" << std::endl;
	c.takeDamage(3);
	std::cout << "Appel de beRepaired(2)" << std::endl;
	c.beRepaired(2);

	std::cout << std::endl << "===Affichage des attributs après actions===" << std::endl;
	std::cout << "Points de vie : " << c.getHitPoints() << std::endl;
	std::cout << "Points d'énergie : " << c.getEnergyPoints() << std::endl;

	std::cout << std::endl << "===Destruction de ClapTrap 'Clap'===" << std::endl;

	return (0);
}