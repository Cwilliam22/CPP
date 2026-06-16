# Résumé MODULE 05 : Exceptions

> Ce module introduit la gestion des erreurs en C++ via les exceptions : `try`, `throw`, `catch`, les classes d'exceptions personnalisées, les classes imbriquées et l'encapsulation sémantique.
> Chaque notion inclut une explication du concept, pourquoi il existe, et un exemple clair pour bien le comprendre.

---

### Notion 1 : Pourquoi les exceptions ?

**Pourquoi ?** En C, les erreurs sont gérées via des codes de retour (`return -1`, `return NULL`). Cette approche mélange le code "normal" et le code de gestion d'erreur, et oblige l'appelant à tester chaque retour. En C++, les exceptions permettent de **séparer** proprement ces deux flux et de **remonter** une erreur jusqu'au niveau capable de la traiter.

**Comparaison :**

```cpp
// ── Style C — codes de retour ──────────────────────────
int diviser(int a, int b, int& resultat) {
    if (b == 0)
        return -1;           // Code d'erreur mélangé au code normal
    resultat = a / b;
    return 0;
}

int main() {
    int res;
    if (diviser(10, 0, res) == -1)       // Obligation de tester à chaque appel
        std::cerr << "Erreur !" << std::endl;
    else
        std::cout << res << std::endl;
    return 0;
}

// ── Style C++ — exceptions ──────────────────────────────
int diviser(int a, int b) {
    if (b == 0)
        throw std::runtime_error("Division par zéro !");  // Lance l'exception
    return a / b;                        // Code normal, sans vérification mélangée
}

int main() {
    try {
        std::cout << diviser(10, 2) << std::endl;  // 5 — OK
        std::cout << diviser(10, 0) << std::endl;  // Lance une exception
        std::cout << "Cette ligne ne s'exécute pas" << std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }
    std::cout << "Le programme continue normalement." << std::endl;
    return 0;
}
```

> 💡 **Ce que fait `throw` :** Il interrompt immédiatement l'exécution et **remonte dans la pile d'appels** (`call stack`) jusqu'à trouver un bloc `catch` compatible. Si aucun `catch` n'est trouvé, le programme appelle `std::terminate()` et se termine.

---

### Notion 2 : La syntaxe `try` / `throw` / `catch`

**Les trois blocs :**

```cpp
try {
    // Code "normal" — ce qu'on essaie de faire
    // Si une erreur survient ici, on throw
}
catch (TypeException& e) {
    // Code de gestion de l'erreur
    // e contient des infos sur l'erreur (e.what())
}
```

**`throw` peut lancer n'importe quel type :**
```cpp
throw 42;                                  // Lance un int
throw std::string("erreur");               // Lance une string
throw std::runtime_error("message");       // Lance un objet exception standard
throw MonException();                      // Lance une exception personnalisée
```

**`catch` attrape par type :**
```cpp
try {
    throw std::runtime_error("problème !");
}
catch (const std::runtime_error& e) {
    // Attrape uniquement les runtime_error
    std::cerr << e.what() << std::endl;
}
catch (const std::exception& e) {
    // Attrape toutes les exceptions dérivées de std::exception
    std::cerr << e.what() << std::endl;
}
catch (...) {
    // Attrape TOUT (y compris les types non-standard)
    std::cerr << "Exception inconnue" << std::endl;
}
```

> ⚠️ **Ordre des `catch` :** Toujours du plus **spécifique** au plus **général**. Si on met `std::exception` en premier, il attrapera tout et les `catch` suivants ne seront jamais atteints.

**Exemple avec plusieurs niveaux d'erreur :**
```cpp
void niveau3() { throw std::runtime_error("Erreur profonde !"); }
void niveau2() { niveau3(); }   // Ne gère pas l'exception → la laisse remonter
void niveau1() { niveau2(); }   // Idem

int main() {
    try {
        niveau1();   // L'exception remonte jusqu'ici
    }
    catch (const std::exception& e) {
        std::cerr << "Attrapée dans main : " << e.what() << std::endl;
    }
    return 0;
}
// Sortie : "Attrapée dans main : Erreur profonde !"
```

---

### Notion 3 : `std::exception` — la classe de base standard

**Pourquoi ?** En C++, `std::exception` est la **classe de base** de toutes les exceptions standard. En faire hériter ses propres exceptions garantit qu'elles peuvent être attrapées par un `catch (std::exception&)` générique, grâce au polymorphisme.

**Hiérarchie standard des exceptions :**
```
std::exception
    ├── std::logic_error
    │       ├── std::invalid_argument
    │       ├── std::out_of_range
    │       └── std::length_error
    └── std::runtime_error
            ├── std::overflow_error
            └── std::underflow_error
```

**La méthode clé — `what()` :**
```cpp
// Déclaration dans std::exception
virtual const char* what() const throw();
//                                 ^^^^^ ne lance pas d'exception elle-même
```
`what()` retourne un message d'erreur sous forme de `const char*`. Elle est virtuelle — on peut la redéfinir dans ses propres classes.

**Pourquoi `const char*` et pas `std::string` ?** Pour des raisons historiques de compatibilité et pour éviter qu'une allocation mémoire dans `what()` provoque elle-même une exception.

---

### Notion 4 : Exceptions personnalisées

**Pourquoi ?** Créer ses propres classes d'exceptions permet de donner un **sens sémantique** aux erreurs, de les typer précisément, et de les attraper séparément.

**Exemple — exception simple :**
```cpp
#include <exception>
#include <stdexcept>

class AgeInvalideException : public std::exception {
public:
    // Redéfinition de what() pour personnaliser le message
    const char* what() const throw() {
        return "Age invalide : doit être entre 0 et 150.";
    }
};

class Personne {
public:
    Personne(std::string nom, int age) : _nom(nom) {
        if (age < 0 || age > 150)
            throw AgeInvalideException();   // Lance notre exception personnalisée
        _age = age;
    }
private:
    std::string _nom;
    int         _age;
};

int main() {
    try {
        Personne p1("Alice", 30);     // ✅ OK
        Personne p2("Bob", 200);      // ❌ Lance AgeInvalideException
    }
    catch (const AgeInvalideException& e) {
        std::cerr << "Erreur spécifique : " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Erreur générique : " << e.what() << std::endl;
    }
    return 0;
}
```

**Exemple — exception avec message dynamique :**
```cpp
#include <sstream>

class GradeInvalideException : public std::exception {
public:
    GradeInvalideException(int grade) {
        std::ostringstream oss;
        oss << "Grade invalide : " << grade << " (doit être entre 1 et 150)";
        _message = oss.str();
    }

    const char* what() const throw() {
        return _message.c_str();
    }

private:
    std::string _message;   // Stocke le message avec la valeur fautive
};

int main() {
    try {
        throw GradeInvalideException(200);
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        // "Grade invalide : 200 (doit être entre 1 et 150)"
    }
    return 0;
}
```

---

### Notion 5 : Classes imbriquées (nested classes)

**Pourquoi ?** Une classe imbriquée est une classe définie **à l'intérieur d'une autre classe**. Elle sert à encapsuler des fonctionnalités étroitement liées à la classe englobante, limite sa visibilité à ce contexte, et évite de polluer l'espace global.

**Syntaxe :**
```cpp
class ClasseEnglobante {
public:
    class ClasseImbriquee {
        // Définie à l'intérieur de ClasseEnglobante
        // Son nom complet est : ClasseEnglobante::ClasseImbriquee
    };
};
```

**Application — exceptions imbriquées dans Bureaucrat :**
```cpp
class Bureaucrat {
public:
    Bureaucrat(const std::string& nom, int grade);

    // Exceptions définies DANS la classe — elles lui appartiennent sémantiquement
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw() {
            return "Grade trop élevé (minimum : 1) !";
        }
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw() {
            return "Grade trop bas (maximum : 150) !";
        }
    };

private:
    const std::string _name;
    int               _grade;  // 1 = plus haut grade, 150 = plus bas grade
};

// Pour les utiliser depuis l'extérieur, on préfixe avec le nom de la classe
int main() {
    try {
        Bureaucrat b("Jean", 0);   // Grade 0 → invalide → throw
    }
    catch (const Bureaucrat::GradeTooHighException& e) {
        //          ^^^^^^^^^^^
        //   Accès via l'opérateur de résolution de portée
        std::cerr << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
```

> 💡 **Avantages des exceptions imbriquées :**
> - `Bureaucrat::GradeTooHighException` exprime clairement que cette erreur appartient au contexte `Bureaucrat`
> - Évite les conflits de noms dans l'espace global
> - Documente la relation entre l'exception et sa classe d'origine

---

### Notion 6 : Encapsulation sémantique

**Pourquoi ?** L'encapsulation sémantique consiste à regrouper ensemble ce qui **appartient logiquement ensemble**. Les classes imbriquées en sont un exemple : en définissant `GradeTooHighException` à l'intérieur de `Bureaucrat`, on dit clairement que cette exception n'a de sens que dans le contexte des bureaucrates.

**Bénéfices :**
```cpp
// ❌ Sans encapsulation sémantique — espace global pollué
class GradeTooHighException : public std::exception { /* ... */ };
class GradeTooLowException  : public std::exception { /* ... */ };
class FormeTooLargeException : public std::exception { /* ... */ };
// ... des dizaines de classes globales sans contexte clair

// ✅ Avec encapsulation sémantique — hiérarchie logique
class Bureaucrat {
    class GradeTooHighException : public std::exception { /* ... */ };
    class GradeTooLowException  : public std::exception { /* ... */ };
};

class Forme {
    class TropGrandeException : public std::exception { /* ... */ };
};
// Chaque exception est dans son "sous-espace de noms" naturel
```

---

### Notion 7 : `throw` dans un constructeur

**Pourquoi ?** Lancer une exception dans un constructeur est la façon idiomatique en C++ d'empêcher la création d'un objet invalide. Si le constructeur `throw`, l'objet n'est **jamais complètement créé** — aucune ressource n'est allouée, aucun destructeur n'est appelé pour cet objet.

```cpp
class Bureaucrat {
public:
    Bureaucrat(const std::string& nom, int grade) : _name(nom) {
        if (grade < 1)
            throw GradeTooHighException();   // L'objet n'est pas créé
        if (grade > 150)
            throw GradeTooLowException();    // L'objet n'est pas créé
        _grade = grade;
        // Si on arrive ici, l'objet est valide — invariant garanti
    }

    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw() { return "Grade trop élevé !"; }
    };
    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw() { return "Grade trop bas !"; }
    };

private:
    const std::string _name;
    int               _grade;
};

int main() {
    try {
        Bureaucrat b1("Alice", 75);    // ✅ Créé normalement
        Bureaucrat b2("Bob", 0);       // ❌ throw → b2 n'existe pas
        Bureaucrat b3("Carol", 200);   // ❌ throw → b3 n'existe pas
    }
    catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << e.what() << std::endl;   // "Grade trop élevé !"
    }
    catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << e.what() << std::endl;   // "Grade trop bas !"
    }
    return 0;
}
```

> 💡 **L'invariant de classe :** Un objet créé avec succès (sans exception) est **toujours dans un état valide**. Lancer une exception dans le constructeur est le moyen de garantir cet invariant — on refuse la création d'un objet incohérent plutôt que de le laisser exister dans un état indéfini.

---

### Notion 8 : `throw` dans une méthode et re-lancer une exception

**Pourquoi ?** Les méthodes peuvent également lancer des exceptions quand une opération est impossible. On peut aussi **re-lancer** (`rethrow`) une exception attrapée pour la propager vers un niveau supérieur.

```cpp
class Bureaucrat {
public:
    Bureaucrat(const std::string& nom, int grade) : _name(nom), _grade(grade) {}

    void incrementGrade() {
        if (_grade <= 1)
            throw GradeTooHighException();   // Déjà au grade maximum
        _grade--;   // Grade 1 = plus haut, donc décrémenter = monter en grade
    }

    void decrementGrade() {
        if (_grade >= 150)
            throw GradeTooLowException();    // Déjà au grade minimum
        _grade++;
    }

    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw() { return "Grade trop élevé !"; }
    };
    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw() { return "Grade trop bas !"; }
    };

private:
    const std::string _name;
    int               _grade;
};

// Re-lancer une exception : attraper, logguer, puis propager
void traiterBureaucrat(Bureaucrat& b) {
    try {
        b.incrementGrade();
    }
    catch (const std::exception& e) {
        std::cerr << "[LOG] Erreur dans traiterBureaucrat : " << e.what() << std::endl;
        throw;   // Re-lance la même exception vers le niveau supérieur
    }
}

int main() {
    Bureaucrat b("Alice", 1);   // Grade maximum déjà atteint
    try {
        traiterBureaucrat(b);
    }
    catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Attrapée dans main : " << e.what() << std::endl;
    }
    return 0;
}
// Sortie :
// [LOG] Erreur dans traiterBureaucrat : Grade trop élevé !
// Attrapée dans main : Grade trop élevé !
```

> 💡 **`throw;` sans argument** re-lance l'exception courante telle quelle, sans créer de copie et sans perdre le type original. C'est la façon correcte de propager une exception après l'avoir partiellement traitée (log, nettoyage…).

---

### Notion 9 : Le polymorphisme au service des exceptions

**Pourquoi ?** Grâce au polymorphisme et à l'héritage de `std::exception`, on peut attraper toutes les exceptions d'une hiérarchie avec un seul `catch` générique, tout en conservant la possibilité d'en attraper certaines spécifiquement.

```cpp
class ErreurBanque : public std::exception {
public:
    ErreurBanque(const std::string& msg) : _msg(msg) {}
    const char* what() const throw() { return _msg.c_str(); }
private:
    std::string _msg;
};

class SoldeInsuffisant  : public ErreurBanque {
public:
    SoldeInsuffisant()  : ErreurBanque("Solde insuffisant !") {}
};

class CompteBloqueException : public ErreurBanque {
public:
    CompteBloqueException() : ErreurBanque("Compte bloqué !") {}
};

int main() {
    try {
        throw SoldeInsuffisant();
    }
    catch (const SoldeInsuffisant& e) {
        // Attrape uniquement SoldeInsuffisant
        std::cerr << "Cas spécifique : " << e.what() << std::endl;
    }
    catch (const ErreurBanque& e) {
        // Attrape toutes les ErreurBanque (sauf celles déjà attrapées)
        std::cerr << "Erreur banque : " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        // Attrape tout le reste
        std::cerr << "Erreur générique : " << e.what() << std::endl;
    }
    return 0;
}
// Sortie : "Cas spécifique : Solde insuffisant !"
```

---

## Notions clés

- Exceptions : séparer code normal et gestion d'erreur
- `try` : bloc d'essai
- `throw` : lance une exception et remonte la pile d'appels
- `catch` : attrape et traite une exception
- `catch (...)` : attrape tout type d'exception
- Ordre des `catch` : du plus spécifique au plus général
- `std::exception` : classe de base de toutes les exceptions standard
- `what()` : retourne `const char*`, virtuelle, redéfinissable, suffixée `throw()`
- `throw;` sans argument : re-lance l'exception courante
- Exception dans un constructeur : empêche la création d'un objet invalide
- Classes imbriquées : classe définie à l'intérieur d'une autre classe
- Accès depuis l'extérieur : `ClasseEnglobante::ClasseImbriquee`
- Encapsulation sémantique : regrouper ce qui appartient logiquement ensemble
- Polymorphisme des exceptions : `catch (std::exception&)` attrape toutes les dérivées
