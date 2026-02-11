#include "Zombie.hpp"

// Appele le constructeur Zombie de la class Zombie pour creer un nouveau Zombie
//  Garder de la place dans la heap (allocation dynamique) 
Zombie* newZombie(std::string name)
{
    Zombie* new_zombie = new Zombie(name);
    return (new_zombie);
}

