#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	std::cout << "Création de FragTrap 'Frag'" << std::endl;
	FragTrap f("Frag");

	std::cout << std::endl << "Appel de attack('ennemi')" << std::endl << std::endl;
	f.attack("ennemi");

	std::cout << std::endl << "Affichage des attributs (hérité de ClapTrap)" << std::endl << std::endl;
	std::cout << "Nom : " << f.getName() << std::endl;
	std::cout << "Points de vie : " << f.getHitPoints() << std::endl;
	std::cout << "Points d'énergie : " << f.getEnergyPoints() << std::endl;
	std::cout << "Dégâts d'attaque : " << f.getAttackDamage() << std::endl;

	std::cout << std::endl << "Appel de highFivesGuys()" << std::endl << std::endl;
	f.highFivesGuys();

	std::cout << std::endl << "Destruction de FragTrap 'Frag'" << std::endl << std::endl;

	return (0);
}