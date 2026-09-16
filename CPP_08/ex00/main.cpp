#include "easyfind.hpp"
#include <list>

int main()
{
    std::vector<int> tab;
    tab.push_back(3);
    tab.push_back(32);
    tab.push_back(1);
    tab.push_back(5);
    tab.push_back(22);
    tab.push_back(9);

    std::cout << "--- Test 1: valeur presente dans un vector ---" << std::endl;
    try
    {
        std::vector<int>::iterator it = easyfind(tab, 22);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "--- Test 2: valeur absente d'un vector ---" << std::endl;
    try
    {
        std::vector<int>::iterator it = easyfind(tab, 100);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::list<int> l;
    l.push_back(7);
    l.push_back(14);
    l.push_back(21);

    std::cout << "--- Test 3: valeur presente dans une list ---" << std::endl;
    try
    {
        std::list<int>::iterator it = easyfind(l, 14);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "--- Test 4: valeur absente d'une list ---" << std::endl;
    try
    {
        std::list<int>::iterator it = easyfind(l, 999);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return (0);
}
