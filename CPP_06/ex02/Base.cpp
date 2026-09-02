#include "Base.hpp"

Base::~Base() {}

Base* generate(void) {
    int choix = rand() % 3;   // 0, 1 ou 2
    if (choix == 0)
        return (new A);
    else if (choix == 1)
        return (new B);
    else
        return (new C);
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base& p) {
   try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    }
    catch (...)
    {
        try
        {
            (void)dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
        }
        catch (...)
        {
            try
            {
                (void)dynamic_cast<C&>(p);
                std::cout << "C" << std::endl;
            }
            catch (...)
            {
                std::cout << "Unknown type" << std::endl;
            }
        }
    }    
}
