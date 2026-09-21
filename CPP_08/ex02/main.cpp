#include "MutantStack.hpp"
#include <string>
#include <list>

static void printResult(const char *out)
{
    std::cout << "\033[36m--- " << out << " ---\033[0m" << std::endl;
}

int main()
{
    // 1. Exemple du sujet
    printResult("Exemple du sujet");
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }

    // 2. Meme scenario avec std::list<int>, pour comparer avec la remarque du sujet :
    printResult("Meme scenario avec std::list<int> (doit donner la meme sortie que ci-dessus)");
    {
        std::list<int> lstack;
        lstack.push_back(5);
        lstack.push_back(17);
        std::cout << lstack.back() << std::endl;
        lstack.pop_back();
        std::cout << lstack.size() << std::endl;
        lstack.push_back(3);
        lstack.push_back(5);
        lstack.push_back(737);
        lstack.push_back(0);
        std::list<int>::iterator it = lstack.begin();
        std::list<int>::iterator ite = lstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }

    // 3. MutantStack sur un autre type que int : std::string
    printResult("MutantStack<std::string>");
    {
        MutantStack<std::string> mstack;
        mstack.push("un");
        mstack.push("deux");
        mstack.push("trois");
        std::cout << "top(): " << mstack.top() << " (attendu trois)" << std::endl;
        mstack.pop();
        std::cout << "size(): " << mstack.size() << " (attendu 2)" << std::endl;
        for (MutantStack<std::string>::iterator it = mstack.begin(); it != mstack.end(); ++it)
            std::cout << *it << std::endl;
    }

    // 4. Constructeur de copie et operator= 
    printResult("Constructeur de copie et operator=");
    {
        MutantStack<int> original;
        original.push(1);
        original.push(2);
        original.push(3);

        MutantStack<int> copy(original);
        MutantStack<int> assigned;
        assigned.push(99);
        assigned = original;

        original.push(4);

        std::cout << "original.size(): " << original.size() << " (attendu 4)" << std::endl;
        std::cout << "copy.size():     " << copy.size() << " (attendu 3, pas affectee par le push sur original)" << std::endl;
        std::cout << "assigned.size(): " << assigned.size() << " (attendu 3)" << std::endl;

        std::cout << "Contenu de copy: ";
        for (MutantStack<int>::iterator it = copy.begin(); it != copy.end(); ++it)
            std::cout << *it << " ";
        std::cout << "(attendu 1 2 3)" << std::endl;
    }

    // 5. MutantStack avec un autre conteneur sous-jacent : std::list au lieu du deque par defaut
    printResult("MutantStack<int, std::list<int> >");
    {
        MutantStack<int, std::list<int> > mstack;
        mstack.push(10);
        mstack.push(20);
        mstack.push(30);
        std::cout << "top(): " << mstack.top() << " (attendu 30)" << std::endl;
        for (MutantStack<int, std::list<int> >::iterator it = mstack.begin(); it != mstack.end(); ++it)
            std::cout << *it << " ";
        std::cout << "(attendu 10 20 30)" << std::endl;
    }

    return (0);
}
