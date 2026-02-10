#include "Zombie.hpp"

int main(void)
{
    int N = 6;
    std::string name = "HordeZombie";

    if (N <= 0)
    {
        std::cout << "Number of zombies must be greater than 0." << std::endl;
        return (1);
    }
    std::cout << "Creating horde of " <<  N  << " zombies named '" << name << "'" << std::endl << std::endl;
    Zombie* horde = zombieHorde(N, name);
    for (int i = 0; i < N; i++)
    {
        std::cout << "Zombie " << "[" << (i + 1) << "]" << ": ";
        horde[i].announce();
    }
    std::cout << "\nDeleting the horde..." << std::endl;
    delete[] horde;
    return (0);
}