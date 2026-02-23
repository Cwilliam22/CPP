#include "ClapTrap.hpp"

#include <iostream>
#include "ClapTrap.hpp"

int main()
{
    std::cout << "=== TEST: ClapTrap Basic Behavior ===" << std::endl;

    ClapTrap clap("Clappy");

    // Test attack
    std::cout << "\n--- Attack Test ---" << std::endl;
    clap.attack("Enemy");

    // Test repair
    std::cout << "\n--- Repair Test ---" << std::endl;
    clap.beRepaired(3);

    // Test takeDamage
    std::cout << "\n--- Take Damage Test ---" << std::endl;
    clap.takeDamage(5);

    // Test attack after damage
    std::cout << "\n--- Attack after damage ---" << std::endl;
    clap.attack("Enemy");

    // Test repair after damage
    std::cout << "\n--- Repair after damage ---" << std::endl;
    clap.beRepaired(2);

    // Test death
    std::cout << "\n--- Death Test ---" << std::endl;
    clap.takeDamage(10); // Should kill it

    // Test attack when dead
    std::cout << "\n--- Attack when dead ---" << std::endl;
    clap.attack("Enemy");

    // Test repair when dead
    std::cout << "\n--- Repair when dead ---" << std::endl;
    clap.beRepaired(5);

    // Test energy depletion
    std::cout << "\n--- Energy Depletion Test ---" << std::endl;
    ClapTrap clap2("Energetic");
    for (int i = 0; i < 11; i++) {
        clap2.attack("Target");
    }

    std::cout << "\n=== TESTS COMPLETED ===" << std::endl;
    return 0;
}