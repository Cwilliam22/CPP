#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"


int main()
{
    std::cout << "========================================" << std::endl;
    std::cout << "   🧪 TEST DE DIAMONDTRAP" << std::endl;
    std::cout << "========================================" << std::endl;

    // Création d'un DiamondTrap
    std::cout << "\n🔹 Création de DiamondTrap 'Bobby'" << std::endl;
    DiamondTrap d("Bobby");

    std::cout << "\n🔹 Appel de whoAmI()" << std::endl;
    d.whoAmI();

    std::cout << "\n🔹 Appel de attack('ennemi')" << std::endl;
    d.attack("ennemi");

    std::cout << "\n🔹 Affichage des attributs (via méthodes de ClapTrap)" << std::endl;
    std::cout << "Nom : " << d.getName() << std::endl;
    std::cout << "Points de vie : " << d.getHitPoints() << std::endl;
    std::cout << "Points d'énergie : " << d.getEnergyPoints() << std::endl;
    std::cout << "Dégâts d'attaque : " << d.getAttackDamage() << std::endl;

    std::cout << "\n🔹 Appel de guardGate() (hérité de ScavTrap)" << std::endl;
    d.guardGate();

    std::cout << "\n🔹 Appel de highFivesGuys() (hérité de FragTrap)" << std::endl;
    d.highFivesGuys();

    std::cout << "\n🔹 Destruction de DiamondTrap 'Bobby'" << std::endl;
    // Le destructeur sera appelé automatiquement ici

    std::cout << "\n========================================" << std::endl;
    std::cout << "     TEST TERMINÉ AVEC SUCCÈS" << std::endl;
    std::cout << "========================================" << std::endl;

    return (0);
}