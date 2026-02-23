#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    std::cout << "=== TEST: ScavTrap Basic Behavior ===" << std::endl;

    ScavTrap scav("Scavy");
    
    // Test attack
    std::cout << "\n--- Attack Test ---" << std::endl;
    scav.attack("Enemy");

    // Test repair
    std::cout << "\n--- Repair Test ---" << std::endl;
    scav.beRepaired(3);
    // Test takeDamage
    std::cout << "\n--- Take Damage Test ---" << std::endl;
    scav.takeDamage(5);

    // Test attack after damage
    std::cout << "\n--- Attack after damage ---" << std::endl;
    scav.attack("Enemy");

    // Test repair after damage
    std::cout << "\n--- Repair after damage ---" << std::endl;
    scav.beRepaired(2);

    // Test death
    std::cout << "\n--- Death Test ---" << std::endl;
    scav.takeDamage(10); // Should kill it

    // Test attack when dead
    std::cout << "\n--- Attack when dead ---" << std::endl;
    scav.attack("Enemy");

    // Test repair when dead
    std::cout << "\n--- Repair when dead ---" << std::endl;
    scav.beRepaired(5);

    // Test energy depletion
    std::cout << "\n--- Energy Depletion Test ---" << std::endl;
    ScavTrap clap2("Energetic");
    for (int i = 0; i < 11; i++) {
        clap2.attack("Target");
    }

    std::cout << "\n=== TESTS COMPLETED ===" << std::endl;

    return (0);
}