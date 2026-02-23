#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"


int main(void)
{
	std::cout << "Création de DiamondTrap 'Diamond'" << std::endl;
	DiamondTrap d("Diamond");

	std::cout << "Appel de whoAmI()" << std::endl;
	d.whoAmI();

	std::cout << std::endl << "Appel de attack('ennemi')" << std::endl << std::endl;
	d.attack("ennemi");

	std::cout << std::endl << "Affichage des attributs (hérité de ClapTrap)" << std::endl << std::endl;
	std::cout << "Nom : " << d.getName() << std::endl;
	std::cout << "Points de vie : " << d.getHitPoints() << std::endl;
	std::cout << "Points d'énergie : " << d.getEnergyPoints() << std::endl;
	std::cout << "Dégâts d'attaque : " << d.getAttackDamage() << std::endl;

	std::cout << std::endl << "Appel de guardGate() (hérité de ScavTrap)" << std::endl << std::endl;
	d.guardGate();

	std::cout << std::endl << "Appel de highFivesGuys() (hérité de FragTrap)" << std::endl << std::endl;
	d.highFivesGuys();

	std::cout << std::endl << "Destruction de DiamondTrap 'Diamond'" << std::endl << std::endl;

	return (0);
}