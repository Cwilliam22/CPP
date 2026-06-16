# Résumé MODULE 04 : Polymorphisme et classes abstraites

> Ce module introduit le polymorphisme, les méthodes virtuelles, la copie profonde et les classes abstraites.
> Chaque notion inclut une explication du concept, pourquoi il existe, et un exemple clair pour bien le comprendre.

---

### Notion 1 : Le polymorphisme

**Pourquoi ?** Le polymorphisme est la capacité à **traiter des objets de types différents de la même manière**, grâce à une interface commune (la classe mère). Il permet d'interagir avec des objets sans connaître leur type concret au moment de l'exécution.

**Analogie :** Un télécommande universelle peut contrôler une télé, un DVD, une chaîne hi-fi. On appuie sur "play" sans savoir quel appareil est connecté — chacun réagit à sa façon.

**Le problème sans polymorphisme :**
```cpp
class Forme {
public:
    void dessiner() { std::cout << "Forme générique" << std::endl; }
};

class Cercle : public Forme {
public:
    void dessiner() { std::cout << "Cercle" << std::endl; }
};

int main() {
    Forme* f = new Cercle();
    f->dessiner();   // ❌ Affiche "Forme générique" — pas "Cercle" !
                     // Le compilateur utilise le TYPE du pointeur (Forme*),
                     // pas le TYPE RÉEL de l'objet (Cercle)
    delete f;
    return 0;
}
```

**La solution — `virtual` :**
```cpp
class Forme {
public:
    virtual void dessiner() { std::cout << "Forme générique" << std::endl; }
};

class Cercle : public Forme {
public:
    virtual void dessiner() { std::cout << "Cercle" << std::endl; }
};

int main() {
    Forme* f = new Cercle();
    f->dessiner();   // ✅ Affiche "Cercle" — le type RÉEL est utilisé
    delete f;
    return 0;
}
```

> 💡 **Le polymorphisme est rendu possible grâce à une abstraction introduite par un pointeur ou une référence vers une classe mère.** Sans pointeur ni référence, il n'y a pas de polymorphisme — une copie par valeur perd l'information du type réel.

---

### Notion 2 : Méthodes virtuelles (`virtual`)

**Pourquoi ?** Le mot-clef `virtual` dit au compilateur d'utiliser le **type réel** de l'objet pour choisir quelle version d'une méthode appeler, plutôt que le type du pointeur ou de la référence.

**Sans `virtual` — résolution statique (à la compilation) :**
```cpp
// Le compilateur décide au moment de la compilation
// selon le TYPE DU POINTEUR, pas l'objet réel
ClapTrap* test = new ScavTrap("Scav");
test->attack("cible");   // ❌ Appelle ClapTrap::attack(), pas ScavTrap::attack()
```

**Avec `virtual` — résolution dynamique (à l'exécution) :**
```cpp
class ClapTrap {
public:
    virtual void attack(const std::string& cible) {
        std::cout << "ClapTrap attaque " << cible << std::endl;
    }
};

class ScavTrap : public ClapTrap {
public:
    virtual void attack(const std::string& cible) {
        std::cout << "ScavTrap attaque férocement " << cible << std::endl;
    }
};

int main() {
    ClapTrap* test = new ScavTrap("Scav");
    test->attack("ennemi");   // ✅ Appelle ScavTrap::attack()
                               // car attack() est virtual dans ClapTrap
    delete test;
    return 0;
}
```

**Exemple avec un tableau polymorphique :**
```cpp
class Animal {
public:
    virtual void parler() const { std::cout << "..." << std::endl; }
    virtual ~Animal() {}
};

class Chat : public Animal {
public:
    virtual void parler() const { std::cout << "Miaou !" << std::endl; }
};

class Chien : public Animal {
public:
    virtual void parler() const { std::cout << "Wouf !" << std::endl; }
};

class Vache : public Animal {
public:
    virtual void parler() const { std::cout << "Meuh !" << std::endl; }
};

int main() {
    Animal* ferme[3] = { new Chat(), new Chien(), new Vache() };

    // On traite tous les animaux de la même façon
    // sans savoir leur type concret
    for (int i = 0; i < 3; i++)
        ferme[i]->parler();   // Miaou ! / Wouf ! / Meuh !

    for (int i = 0; i < 3; i++)
        delete ferme[i];
    return 0;
}
```

> 💡 **Méthode virtuelle vs redéfinition simple :**
> Une méthode peut être redéfinie sans `virtual` (comme dans le module 03), mais dans ce cas la résolution est statique : c'est toujours la version du type du pointeur qui est appelée. Avec `virtual`, c'est le type réel de l'objet qui décide.

---

### Notion 3 : Le destructeur virtuel

**Pourquoi ?** Si une classe est utilisée comme classe de base (avec des pointeurs), son destructeur **doit** être déclaré `virtual`. Sans cela, `delete` sur un pointeur de type parent n'appelle que le destructeur de la classe mère — le destructeur de la fille n'est jamais appelé, causant une **fuite mémoire**.

**Exemple du problème :**
```cpp
class Base {
public:
    ~Base() { std::cout << "Destructeur Base" << std::endl; }
    //  ↑ Non virtual → PROBLÈME !
};

class Fille : public Base {
public:
    Fille()  { _data = new int(42); }
    ~Fille() {
        delete _data;   // Cette ligne ne sera JAMAIS appelée !
        std::cout << "Destructeur Fille" << std::endl;
    }
private:
    int* _data;   // Fuite mémoire garantie
};

int main() {
    Base* b = new Fille();
    delete b;   // ❌ Appelle seulement ~Base() → ~Fille() jamais appelé
                //    _data n'est jamais libéré → fuite mémoire
    return 0;
}
```

**La solution — destructeur virtuel :**
```cpp
class Base {
public:
    virtual ~Base() { std::cout << "Destructeur Base" << std::endl; }
    //  ↑ virtual → le bon destructeur sera toujours appelé
};

class Fille : public Base {
public:
    Fille()          { _data = new int(42); }
    virtual ~Fille() {
        delete _data;   // ✅ Appelé correctement maintenant
        std::cout << "Destructeur Fille" << std::endl;
    }
private:
    int* _data;
};

int main() {
    Base* b = new Fille();
    delete b;   // ✅ Appelle ~Fille() PUIS ~Base() — ordre correct
    // Sortie :
    // Destructeur Fille
    // Destructeur Base
    return 0;
}
```

> 💡 **Règle absolue :** Toute classe qui a au moins une méthode `virtual` doit avoir un destructeur `virtual`. Sans cela, `delete` via un pointeur parent cause une fuite mémoire.

---

### Notion 4 : Copie profonde (Deep Copy) vs copie superficielle (Shallow Copy)

**Pourquoi ?** Quand un attribut est un **pointeur**, la copie par défaut (générée automatiquement par le compilateur) copie l'**adresse**, pas les données. Les deux objets pointent alors vers la même zone mémoire — si l'un est détruit, l'autre accède à de la mémoire invalide.

**Illustration du problème — shallow copy :**
```
Objet A :  _data → [ 42 ]
                      ↑
Objet B :  _data ─────┘   ← B et A partagent la MÊME zone mémoire !

Si A est détruit → delete _data → la zone est libérée
Si B est ensuite détruit → delete _data → CRASH (double free !)
```

**Exemple concret :**
```cpp
class Cerveau {
public:
    Cerveau() : _idees(new std::string[100]) {}

    // ✅ Constructeur de copie — deep copy
    Cerveau(const Cerveau& other) : _idees(new std::string[100]) {
        for (int i = 0; i < 100; i++)
            _idees[i] = other._idees[i];   // Copie le CONTENU, pas l'adresse
    }

    // ✅ Opérateur d'affectation — deep copy
    Cerveau& operator=(const Cerveau& other) {
        if (this != &other) {
            for (int i = 0; i < 100; i++)
                _idees[i] = other._idees[i];
        }
        return (*this);
    }

    ~Cerveau() { delete[] _idees; }   // Chaque Cerveau gère sa propre mémoire

private:
    std::string* _idees;
};

class Animal {
public:
    Animal() : _cerveau(new Cerveau()) {}

    // Deep copy : alloue un NOUVEAU Cerveau et copie son contenu
    Animal(const Animal& other) : _cerveau(new Cerveau(*other._cerveau)) {}

    Animal& operator=(const Animal& other) {
        if (this != &other) {
            delete _cerveau;
            _cerveau = new Cerveau(*other._cerveau);   // Nouveau Cerveau
        }
        return (*this);
    }

    ~Animal() { delete _cerveau; }   // Chaque Animal est propriétaire de son Cerveau

private:
    Cerveau* _cerveau;
};

int main() {
    Animal a1;
    Animal a2(a1);   // a2 a son propre Cerveau — pas le même que a1
    Animal a3;
    a3 = a1;         // a3 a son propre Cerveau — pas le même que a1

    // Destruction sans crash : chacun libère son propre Cerveau
    return 0;
}
```

> 💡 **Règle :** Dès qu'une classe possède un attribut alloué dynamiquement (`new`), il faut implémenter les 4 éléments de l'OCF avec une deep copy. Sinon la copie par défaut crée un double pointeur vers la même mémoire.

---

### Notion 5 : Le WrongAnimal — pourquoi `virtual` est indispensable

**Pourquoi ?** Pour bien comprendre l'utilité de `virtual`, on peut comparer une hiérarchie correcte (`Animal` avec `virtual`) et une incorrecte (`WrongAnimal` sans `virtual`).

```cpp
// ── Hiérarchie CORRECTE ─────────────────────────────
class Animal {
public:
    virtual void makeSound() const { std::cout << "Son générique" << std::endl; }
    virtual ~Animal() {}
};

class Cat : public Animal {
public:
    virtual void makeSound() const { std::cout << "Miaou !" << std::endl; }
};

// ── Hiérarchie INCORRECTE ───────────────────────────
class WrongAnimal {
public:
    void makeSound() const { std::cout << "Son wrong générique" << std::endl; }
    // ↑ Pas virtual → résolution statique
};

class WrongCat : public WrongAnimal {
public:
    void makeSound() const { std::cout << "Miaou wrong !" << std::endl; }
};

int main() {
    // Hiérarchie correcte
    const Animal* a = new Cat();
    a->makeSound();   // ✅ "Miaou !" — type réel utilisé grâce à virtual

    // Hiérarchie incorrecte
    const WrongAnimal* wa = new WrongCat();
    wa->makeSound();  // ❌ "Son wrong générique" — type du pointeur utilisé
                      //    makeSound() n'est pas virtual dans WrongAnimal

    delete a;
    delete wa;
    return 0;
}
```

---

### Notion 6 : Classes abstraites et méthodes virtuelles pures

**Pourquoi ?** Une **classe abstraite** est une classe qui ne peut pas être instanciée directement. Elle sert de **modèle** (contrat) pour ses classes dérivées, en les forçant à implémenter certaines méthodes.

**Une classe devient abstraite dès qu'elle possède au moins une méthode virtuelle pure.**

**Syntaxe — méthode virtuelle pure :**
```cpp
virtual void methode() const = 0;
//                            ^^^
//                    "= 0" → virtuelle pure
//                    → pas de corps dans la classe mère
//                    → OBLIGATOIRE à implémenter dans les filles
```

**Exemple :**
```cpp
class Forme {
public:
    virtual double aire()      const = 0;   // Virtuelle pure — pas de corps
    virtual void   dessiner()  const = 0;   // Virtuelle pure — pas de corps
    virtual ~Forme() {}                     // Destructeur virtual — obligatoire !
};

// Forme f;   // ❌ ERREUR DE COMPILATION : Forme est abstraite

class Cercle : public Forme {
public:
    Cercle(double r) : _rayon(r) {}

    // OBLIGATOIRE : implémenter toutes les virtuelles pures
    virtual double aire()     const { return 3.14159 * _rayon * _rayon; }
    virtual void   dessiner() const { std::cout << "Cercle r=" << _rayon << std::endl; }

private:
    double _rayon;
};

class Rectangle : public Forme {
public:
    Rectangle(double l, double h) : _l(l), _h(h) {}

    virtual double aire()     const { return _l * _h; }
    virtual void   dessiner() const { std::cout << "Rectangle " << _l << "x" << _h << std::endl; }

private:
    double _l, _h;
};

int main() {
    // On manipule des Forme* mais on stocke des objets concrets
    Forme* formes[2] = { new Cercle(5), new Rectangle(3, 4) };

    for (int i = 0; i < 2; i++) {
        formes[i]->dessiner();
        std::cout << "Aire : " << formes[i]->aire() << std::endl;
    }

    for (int i = 0; i < 2; i++)
        delete formes[i];   // ✅ ~Forme() est virtual → bonne destruction
    return 0;
}
```

**Méthode virtuelle vs virtuelle pure :**

| | `virtual void f()` | `virtual void f() = 0` |
|---|---|---|
| Corps dans la classe mère | ✅ Oui (comportement par défaut) | ❌ Non |
| Classe mère instanciable | ✅ Oui | ❌ Non (abstraite) |
| Redéfinition dans la fille | Optionnelle | **Obligatoire** |

> 💡 **Analogie :** Une classe abstraite est comme un contrat de travail qui dit "tout employé DOIT savoir faire X et Y". Elle ne dit pas comment le faire — chaque employé (classe dérivée) l'implémente à sa façon.

---

### Notion 7 : Interface via classe abstraite

**Pourquoi ?** Une classe entièrement abstraite (toutes ses méthodes sont virtuelles pures) joue le rôle d'**interface** : elle définit un contrat sans aucune implémentation. C'est le moyen en C++ de garantir qu'un ensemble de classes expose les mêmes méthodes.

```cpp
// Interface : 100% virtuelle pure, aucune implémentation
class ILogger {
public:
    virtual void log(const std::string& message)  = 0;
    virtual void warn(const std::string& message) = 0;
    virtual void error(const std::string& message) = 0;
    virtual ~ILogger() {}
};

// Implémentation 1 : affiche dans le terminal
class ConsoleLogger : public ILogger {
public:
    void log(const std::string& msg)   { std::cout << "[LOG]   " << msg << std::endl; }
    void warn(const std::string& msg)  { std::cout << "[WARN]  " << msg << std::endl; }
    void error(const std::string& msg) { std::cout << "[ERROR] " << msg << std::endl; }
};

// Implémentation 2 : écrit dans un fichier
class FileLogger : public ILogger {
public:
    void log(const std::string& msg)   { /* écriture dans fichier */ }
    void warn(const std::string& msg)  { /* écriture dans fichier */ }
    void error(const std::string& msg) { /* écriture dans fichier */ }
};

// Le code appelant ne sait pas quelle implémentation il utilise
void faireQuelqueChose(ILogger& logger) {
    logger.log("Démarrage");
    logger.warn("Attention");
    logger.error("Problème !");
}

int main() {
    ConsoleLogger cl;
    faireQuelqueChose(cl);   // Affiche dans le terminal
    return 0;
}
```

---

## Notions clés

- Polymorphisme : traiter des objets de types différents via une interface commune
- Possible uniquement via **pointeur** ou **référence** vers la classe mère
- `virtual` : résolution dynamique (type réel) vs résolution statique (type du pointeur)
- Destructeur `virtual` : **obligatoire** si la classe est utilisée comme base avec `delete`
- Sans destructeur `virtual` → fuite mémoire lors du `delete` via pointeur parent
- Shallow copy : copie l'adresse (dangereux avec pointeurs)
- Deep copy : alloue une nouvelle zone mémoire et copie le contenu
- `WrongAnimal` : démonstration du comportement sans `virtual`
- Méthode virtuelle pure : `virtual void f() = 0` — pas de corps, doit être implémentée
- Classe abstraite : au moins une méthode virtuelle pure → ne peut pas être instanciée
- Interface : classe 100% abstraite servant de contrat
- Si une classe dérivée n'implémente pas toutes les virtuelles pures → elle est aussi abstraite
