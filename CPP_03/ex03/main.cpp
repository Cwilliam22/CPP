#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"


int main(void)
{
	std::cout << "===Création de DiamondTrap 'Diamond'===" << std::endl;
	DiamondTrap diamond("Diamond");

	std::cout << std::endl << "===Affichage des attributs===" << std::endl;
	std::cout << "Nom : " << diamond.getName() << std::endl;
	std::cout << "Points de vie : " << diamond.getHitPoints() << " (FragTrap: 100)" << std::endl;
	std::cout << "Points d'énergie : " << diamond.getEnergyPoints() << " (ScavTrap: 50)" << std::endl;
	std::cout << "Dégâts d'attaque : " << diamond.getAttackDamage() << " (FragTrap: 30)" << std::endl;

	std::cout << std::endl << "===Actions===" << std::endl;
	std::cout << "Testing whoAmI" << std::endl;
	diamond.whoAmI();

	std::cout << "Testing attack (ScavTrap's)" << std::endl;
	diamond.attack("Enemy");

	std::cout << "Testing inherited special abilities" << std::endl;
	diamond.guardGate();
	diamond.highFivesGuys();

	std::cout << "Testing inherited functions" << std::endl;
	diamond.takeDamage(30);
	diamond.beRepaired(10);

	std::cout << "\n=== Testing copy ===" << std::endl;
	DiamondTrap diamond2(diamond);
	diamond2.whoAmI();

	std::cout << "\n=== Destruction (reverse order) ===" << std::endl;

	return (0);
}