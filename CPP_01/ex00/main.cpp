#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
        this->_name = name;
		return ;
}

Zombie::~Zombie()
{
    std::cout << _name << " is destroyed" << std::endl;
    return ;
}

int main(void)
{
    Zombie* heapZombie = newZombie("HeapZombie");
    heapZombie->announce();
    randomChump("StackZombie");
    delete heapZombie;
    return (0);
}
