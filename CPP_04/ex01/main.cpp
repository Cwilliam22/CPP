#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "=== Subject tests ===" << std::endl;

    std::cout << std::endl << "---Constructors---" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << std::endl << "---Animal type---" << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    std::cout << std::endl << "---Animal noise---" << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    std::cout << std::endl << "---Destructors---" << std::endl;
    delete meta;
    delete i;
    delete j;

    std::cout << std::endl << "=== Additional tests (Wrong) ===" << std::endl;

    std::cout << std::endl << "---Wrong Destructors---" << std::endl;
    const WrongAnimal* wrong_meta = new WrongAnimal();
    const WrongAnimal* wrong_i = new WrongCat();

    std::cout << std::endl << "---Wrong Animal type---" << std::endl;
    std::cout << wrong_i->getType() << " " << std::endl;

    std::cout << std::endl << "---Wrong Animal noise---" << std::endl;
    wrong_i->makeSound();
    wrong_meta->makeSound();

    std::cout << std::endl << "---Wrong Destructors---" << std::endl;
    delete wrong_meta;
    delete wrong_i;

    std::cout << std::endl << "=== Additional tests ===" << std::endl;
    std::cout << std::endl << "---Constructors---" << std::endl;
	Dog dog;
	Cat cat;

    std::cout << std::endl << "---Animal noise---" << std::endl;
	dog.makeSound();
	cat.makeSound();

	std::cout << std::endl << "=== Copy tests ===" << std::endl;
    std::cout << std::endl << "---Constructors---" << std::endl;
    Dog dog2(dog);

    std::cout << std::endl << "---Animal noise---" << std::endl;
	dog2.makeSound();
    std::cout << std::endl << "---Destructors---" << std::endl;

    return (0);
}