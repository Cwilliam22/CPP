#include "Span.hpp"

static void printResult(const char *label)
{
    std::cout << "----- " << label << " -----" << std::endl;
}

int main()
{
    // 1. Exemple du sujet : Span(5) rempli de 6, 3, 17, 9, 11
    printResult("Exemple du sujet");
    {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "shortestSpan(): " << sp.shortestSpan() << " (attendu 2)" << std::endl;
        std::cout << "longestSpan():  " << sp.longestSpan() << " (attendu 14)" << std::endl;
    }

    // 2. Capacite depassee -> TooMuchNumException
    printResult("Capacite depassee");
    {
        Span sp(2);
        sp.addNumber(1);
        sp.addNumber(2);
        try
        {
            sp.addNumber(3);
            std::cout << "Pas d'exception (INATTENDU)" << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << "Exception attendue: " << e.what() << std::endl;
        }
    }

    // 3. Span vide -> NeedMoreNumException
    printResult("Span vide");
    {
        Span sp(5);
        try
        {
            sp.shortestSpan();
            std::cout << "Pas d'exception (INATTENDU)" << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << "Exception attendue: " << e.what() << std::endl;
        }
    }

    // 4. Span a un seul element -> NeedMoreNumException
    printResult("Span a un seul element");
    {
        Span sp(5);
        sp.addNumber(42);
        try
        {
            sp.longestSpan();
            std::cout << "Pas d'exception (INATTENDU)" << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << "Exception attendue: " << e.what() << std::endl;
        }
    }

    // 5. Doublons -> shortestSpan == 0
    printResult("Doublons");
    {
        Span sp(3);
        sp.addNumber(5);
        sp.addNumber(5);
        sp.addNumber(9);
        std::cout << "shortestSpan(): " << sp.shortestSpan() << " (attendu 0)" << std::endl;
    }

    // 6. Nombres negatifs
    printResult("Nombres negatifs");
    {
        Span sp(4);
        sp.addNumber(-10);
        sp.addNumber(-3);
        sp.addNumber(-7);
        sp.addNumber(0);
        std::cout << "shortestSpan(): " << sp.shortestSpan() << " (attendu 3, entre -10 et -7)" << std::endl;
        std::cout << "longestSpan():  " << sp.longestSpan() << " (attendu 10, entre -10 et 0)" << std::endl;
    }

    // 7. Span minimal a 2 elements
    printResult("Span a 2 elements");
    {
        Span sp(2);
        sp.addNumber(4);
        sp.addNumber(9);
        std::cout << "shortestSpan(): " << sp.shortestSpan() << " (attendu 5)" << std::endl;
        std::cout << "longestSpan():  " << sp.longestSpan() << " (attendu 5)" << std::endl;
    }

    // 8. Borne exacte legitime : 0 et INT_MAX -> pas d'exception, span == INT_MAX
    printResult("Borne exacte (0 et INT_MAX)");
    {
        Span sp(2);
        sp.addNumber(0);
        sp.addNumber(INT_MAX);
        try
        {
            std::cout << "shortestSpan(): " << sp.shortestSpan() << " (attendu " << INT_MAX << ")" << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << "Exception INATTENDUE: " << e.what() << std::endl;
        }
    }

    // 9. Vrai overflow : INT_MIN et INT_MAX -> OverflowException
    printResult("Vrai overflow (INT_MIN et INT_MAX)");
    {
        Span sp(2);
        sp.addNumber(INT_MIN);
        sp.addNumber(INT_MAX);
        try
        {
            double r = sp.shortestSpan();
            std::cout << "Pas d'exception (INATTENDU), obtenu: " << r << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << "Exception attendue: " << e.what() << std::endl;
        }
    }

    // 10. Ecart enorme non retenu (regression du faux positif) -> pas d'exception
    printResult("Ecart enorme non retenu (regression)");
    {
        Span sp(4);
        sp.addNumber(INT_MIN);
        sp.addNumber(2000000000);
        sp.addNumber(2000000001);
        sp.addNumber(INT_MAX);
        try
        {
            std::cout << "shortestSpan(): " << sp.shortestSpan() << " (attendu 1)" << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << "Exception INATTENDUE: " << e.what() << std::endl;
        }
    }

    // 11. Constructeur de copie / operator= (Orthodox Canonical Form)
    printResult("Constructeur de copie et operator=");
    {
        Span sp(3);
        sp.addNumber(1);
        sp.addNumber(2);
        Span copy(sp);
        Span assigned(3);
        assigned = sp;
        std::cout << "copy.shortestSpan():     " << copy.shortestSpan() << " (attendu 1)" << std::endl;
        std::cout << "assigned.shortestSpan(): " << assigned.shortestSpan() << " (attendu 1)" << std::endl;
    }

    // 12. Test exige par le sujet : au moins 10 000 nombres
    printResult("Stress test : 10 000 nombres");
    {
        Span sp(10000);
        for (int i = 0; i < 10000; i++)
            sp.addNumber(-5000000 + i * 977);
        std::cout << "shortestSpan(): " << sp.shortestSpan() << " (attendu 977)" << std::endl;
        std::cout << "longestSpan():  " << sp.longestSpan() << " (attendu 9769023)" << std::endl;
    }

    return (0);
}
