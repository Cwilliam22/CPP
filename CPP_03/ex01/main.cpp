#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	std::cout << "====Création de ScavTrap 'Scav'===" << std::endl;
	ScavTrap s("Scav");

	std::cout << std::endl << "===Affichage des attributs initiaux===" << std::endl;
	std::cout << "Nom : " << s.getName() << std::endl;
	std::cout << "Points de vie : " << s.getHitPoints() << std::endl;
	std::cout << "Points d'énergie : " << s.getEnergyPoints() << std::endl;
	std::cout << "Dégâts d'attaque : " << s.getAttackDamage() << std::endl;

	std::cout << std::endl << "===Actions===" << std::endl;
	std::cout << "Appel de attack('ennemi')" << std::endl;
	s.attack("ennemi");

	std::cout << std::endl << "===Appel de guardGate()===" << std::endl;
	s.guardGate();

	std::cout << std::endl << "===Affichage des attributs après actions===" << std::endl;
	std::cout << "Points de vie : " << s.getHitPoints() << std::endl;
	std::cout << "Points d'énergie : " << s.getEnergyPoints() << std::endl;

	std::cout << std::endl << "===Destruction de ScavTrap 'Scav'===" << std::endl;

	return (0);
}