#include "ClapTrap.hpp"
#include "ScaveTrap.hpp"

int main()
{
    std::cout << "=== TEST: ScaveTrap Basic Behavior ===" << std::endl;

    ScaveTrap scave("Scavy");
    
    // Test attack
    std::cout << "\n--- Attack Test ---" << std::endl;
    scave.attack("Enemy");

    // Test repair
    std::cout << "\n--- Repair Test ---" << std::endl;
    scave.beRepaired(3);
    // Test takeDamage
    std::cout << "\n--- Take Damage Test ---" << std::endl;
    scave.takeDamage(5);

    // Test attack after damage
    std::cout << "\n--- Attack after damage ---" << std::endl;
    scave.attack("Enemy");

    // Test repair after damage
    std::cout << "\n--- Repair after damage ---" << std::endl;
    scave.beRepaired(2);

    // Test death
    std::cout << "\n--- Death Test ---" << std::endl;
    scave.takeDamage(10); // Should kill it

    // Test attack when dead
    std::cout << "\n--- Attack when dead ---" << std::endl;
    scave.attack("Enemy");

    // Test repair when dead
    std::cout << "\n--- Repair when dead ---" << std::endl;
    scave.beRepaired(5);

    // Test energy depletion
    std::cout << "\n--- Energy Depletion Test ---" << std::endl;
    ScaveTrap clap2("Energetic");
    for (int i = 0; i < 11; i++) {
        clap2.attack("Target");
    }

    std::cout << "\n=== TESTS COMPLETED ===" << std::endl;

    return (0);
}