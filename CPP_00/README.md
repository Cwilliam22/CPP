# Résumé MODULE 00 : Introduction à la POO et aux classes

> Ce module est le point d'entrée dans la programmation orientée objet (POO) en C++.
> Chaque notion inclut une explication du concept, pourquoi il existe, et un exemple clair pour bien le comprendre.

---

### Notion 1 : Namespaces

**Pourquoi ?** En C++, quand les projets grandissent, des conflits de noms peuvent apparaître (deux fonctions `max()` dans deux bibliothèques différentes, par exemple). Les namespaces sont des **sacs à notions** : ils regroupent des identifiants sous un nom commun pour éviter ces collisions.

**Exemple :**
```cpp
namespace Mathematiques {
    int max(int a, int b) { return a > b ? a : b; }
}

namespace Jeu {
    int max(int a, int b) { return a > b ? a : b; }  // Même nom, pas de conflit !
}

int main() {
    std::cout << Mathematiques::max(3, 5) << std::endl;  // 5
    std::cout << Jeu::max(10, 2) << std::endl;           // 10
    return 0;
}
```

L'opérateur `::` s'appelle l'**opérateur de résolution de portée**. Il indique dans quel namespace chercher l'identifiant.

Le namespace le plus utilisé est `std` (la bibliothèque standard C++) : c'est pourquoi on écrit `std::cout`, `std::string`, etc.

> 💡 On peut écrire `using namespace std;` pour éviter de répéter `std::` partout, mais c'est **déconseillé** dans les headers car cela pollue la portée globale de tous les fichiers qui incluent ce header.

---

### Notion 2 : Flux d'entrée/sortie standard (`iostream`)

**Pourquoi ?** C++ remplace `printf` et `scanf` par un système de **flux** (streams) plus sûr et extensible.

| Flux | Rôle | Équivalent C |
|------|------|-------------|
| `std::cout` | Sortie standard (affichage) | `printf` |
| `std::cin` | Entrée standard (saisie) | `scanf` |
| `std::cerr` | Sortie d'erreur | `fprintf(stderr, ...)` |
| `std::endl` | Fin de ligne + vidage du buffer | `\n` (+ flush) |

**Exemple :**
```cpp
#include <iostream>
#include <string>

int main() {
    std::string nom;

    std::cout << "Entrez votre nom : ";   // << envoie vers le flux
    std::cin >> nom;                       // >> lit depuis le flux

    std::cout << "Bonjour, " << nom << " !" << std::endl;

    // Affichage d'une erreur sur la sortie d'erreur
    std::cerr << "Attention : quelque chose s'est mal passé." << std::endl;

    return 0;
}
```

> 💡 **`<<` et `>>`** indiquent la **direction du flux** : `<<` envoie des données vers le flux, `>>` en extrait.

---

### Notion 3 : `std::string` et manipulation de chaînes

**Pourquoi ?** En C, on manipule les chaînes avec des tableaux de `char` et des fonctions comme `strlen`. C++ propose `std::string`, qui gère automatiquement la mémoire et offre des méthodes pratiques.

**Exemple :**
```cpp
#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::string mot = "bonjour";

    // Accès à la longueur
    std::cout << mot.length() << std::endl;  // 7

    // Concaténation
    std::string phrase = mot + " le monde";
    std::cout << phrase << std::endl;  // "bonjour le monde"

    // Conversion en majuscules caractère par caractère
    for (size_t i = 0; i < mot.length(); i++)
        mot[i] = std::toupper(mot[i]);
    std::cout << mot << std::endl;  // "BONJOUR"

    return 0;
}
```
Pas besoin de `malloc`, pas de taille fixe à gérer. `std::string` s'occupe de tout.

---

### Notion 4 : Les classes — définition, instance et encapsulation

**Pourquoi ?** Une classe est un **moule** (plan, modèle) qui décrit la structure et le comportement d'un objet. Une **instance** est un objet concret créé à partir de ce moule — chaque instance possède ses propres données tout en partageant la structure définie par la classe.

```
Classe  →  moule à gâteau (le plan)
Instance →  le gâteau (l'objet concret)
```

L'**encapsulation** protège les données internes via `private` : on ne laisse pas l'extérieur modifier directement l'état interne d'un objet.

**Exemple :**
```cpp
#include <iostream>
#include <string>

class Voiture {
public:
    // Méthodes accessibles depuis l'extérieur
    void setVitesse(int v) { _vitesse = v; }
    int  getVitesse() const { return _vitesse; }
    void afficher() const {
        std::cout << "Vitesse : " << _vitesse << " km/h" << std::endl;
    }

private:
    // Données protégées : inaccessibles depuis l'extérieur
    int _vitesse;
};

int main() {
    Voiture v;             // v est une INSTANCE de la classe Voiture
    v.setVitesse(130);
    v.afficher();          // "Vitesse : 130 km/h"
    // v._vitesse = 200;   // ❌ Erreur de compilation ! _vitesse est privé
    return 0;
}
```

> 💡 **Convention :** Les attributs privés sont souvent préfixés d'un underscore (`_vitesse`) pour les identifier facilement dans le code.

---

### Notion 5 : `class` vs `struct`

**Pourquoi ?** En C++, `struct` et `class` sont quasiment identiques. La seule différence est la **visibilité par défaut** de leurs membres :

| | `struct` | `class` |
|---|---|---|
| Visibilité par défaut | `public` | `private` |
| Constructeur/destructeur | ✅ Oui | ✅ Oui |
| Méthodes membres | ✅ Oui | ✅ Oui |

**Exemple :**
```cpp
struct Point {
    int x;  // public par défaut
    int y;  // public par défaut
};

class Cercle {
    float _rayon;  // private par défaut
public:
    Cercle(float r) : _rayon(r) {}
    float getRayon() const { return _rayon; }
};

int main() {
    Point p;
    p.x = 3;    // ✅ Accessible directement (public par défaut)
    p.y = 4;

    Cercle c(5.0f);
    // c._rayon = 2.0f;  // ❌ Privé par défaut dans class
    std::cout << c.getRayon() << std::endl;  // 5
    return 0;
}
```

> 💡 En pratique : `struct` pour des données simples sans logique, `class` pour tout ce qui nécessite de l'encapsulation.

---

### Notion 6 : Constructeur et destructeur

**Pourquoi ?** Le constructeur initialise l'objet à sa création. Le destructeur libère les ressources à sa destruction. Ils n'ont **pas de type de retour** — c'est un protocole automatique du langage.

**Syntaxe :**
```cpp
// Dans le header (.hpp)
class Lampe {
public:
    Lampe(std::string couleur);  // Constructeur
    ~Lampe();                    // Destructeur (préfixé ~)
private:
    std::string _couleur;
};

// Dans le .cpp
Lampe::Lampe(std::string couleur) {   // NomClasse::NomClasse
    _couleur = couleur;
    std::cout << "Lampe " << _couleur << " allumée !" << std::endl;
    return ;
}

Lampe::~Lampe() {                     // NomClasse::~NomClasse
    std::cout << "Lampe " << _couleur << " éteinte." << std::endl;
    return ;
}
```

**Exemple d'utilisation :**
```cpp
int main() {
    Lampe rouge("rouge");    // → "Lampe rouge allumée !"
    {
        Lampe bleue("bleue"); // → "Lampe bleue allumée !"
    }                         // → "Lampe bleue éteinte." (fin du bloc)
    return 0;
}                             // → "Lampe rouge éteinte." (fin du main)
```
Le destructeur est appelé **automatiquement** dès que l'objet sort de sa portée.

---

### Notion 7 : Attributs membres et fonctions membres

**Pourquoi ?** Les **attributs membres** sont les variables propres à chaque instance. Les **fonctions membres** (méthodes) sont les comportements que peut avoir chaque instance. Chaque instance a ses propres valeurs d'attributs.

**Syntaxe d'une fonction membre :**
```
type_retour  NomClasse::NomFonction(arguments)
```

**Exemple :**
```cpp
class Rectangle {
public:
    Rectangle(int largeur, int hauteur);
    ~Rectangle();

    int  aire(void) const;      // Fonction membre
    void afficher(void) const;  // Fonction membre

private:
    int _largeur;   // Attribut membre
    int _hauteur;   // Attribut membre
};

Rectangle::Rectangle(int largeur, int hauteur) {
    _largeur = largeur;
    _hauteur = hauteur;
    return ;
}

Rectangle::~Rectangle() { return ; }

int Rectangle::aire(void) const {
    return (_largeur * _hauteur);
}

void Rectangle::afficher(void) const {
    std::cout << _largeur << " x " << _hauteur
              << " = " << aire() << std::endl;
}

int main() {
    Rectangle r1(3, 4);
    Rectangle r2(10, 2);

    r1.afficher();  // "3 x 4 = 12"
    r2.afficher();  // "10 x 2 = 20"
    // r1 et r2 ont leurs propres _largeur et _hauteur
    return 0;
}
```

---

### Notion 8 : Le pointeur `this`

**Pourquoi ?** À l'intérieur d'une méthode, `this` est un **pointeur implicite** qui pointe vers l'instance courante (l'objet sur lequel la méthode a été appelée). Il est passé automatiquement par le compilateur — on ne le voit pas dans les paramètres mais il est toujours là.

**Exemple :**
```cpp
class Compteur {
public:
    Compteur(int valeur) {
        this->_valeur = valeur;         // this-> désigne cet objet précis
        std::cout << "Valeur : " << this->_valeur << std::endl;
    }

    // Utile pour lever l'ambiguïté quand le paramètre a le même nom que l'attribut
    void setValeur(int valeur) {
        this->_valeur = valeur;  // this->_valeur = attribut, valeur = paramètre
    }

    // Retourner *this permet de chaîner les appels
    Compteur& incrementer() {
        this->_valeur++;
        return (*this);
    }

private:
    int _valeur;
};

int main() {
    Compteur c(0);
    c.incrementer().incrementer().incrementer();  // Chaînage grâce à *this
    return 0;
}
```

> 💡 `this` est un pointeur, donc on accède aux membres avec `this->membre`. `*this` désigne l'objet lui-même.

---

### Notion 9 : Liste d'initialisation

**Pourquoi ?** C'est une syntaxe alternative (et souvent préférable) pour initialiser les attributs dans le constructeur. Elle est **obligatoire** pour les attributs `const` et les références, et plus efficace en général.

**Méthode classique (dans le corps du constructeur) :**
```cpp
class Personne {
public:
    Personne(std::string nom, int age) {
        _nom = nom;    // Assignation (l'attribut est d'abord créé, puis assigné)
        _age = age;
    }
private:
    std::string _nom;
    int         _age;
};
```

**Méthode avec liste d'initialisation (préférable) :**
```cpp
class Personne {
public:
    //                         ↓ Liste d'initialisation (après le :)
    Personne(std::string nom, int age) : _nom(nom), _age(age) {
        // Les attributs sont déjà initialisés ici
        std::cout << "Personne créée : " << _nom << std::endl;
        return ;
    }
private:
    std::string _nom;
    int         _age;
};
```

**Cas où la liste d'initialisation est OBLIGATOIRE :**
```cpp
class Config {
public:
    Config(float pi, int id) : _pi(pi), _id(id) {
        // Sans liste d'initialisation, impossible d'initialiser _pi (const)
        // this->_pi = pi;  // ❌ Erreur : on ne peut pas assigner une constante
    }
private:
    float const _pi;  // Constante : doit être initialisée, pas assignée
    int const   _id;
};
```

> 💡 **Distinction importante :** dans le corps du constructeur, on **assigne** une valeur. Dans la liste d'initialisation, on **initialise** directement. Pour un `const`, seule l'initialisation est possible.

---

### Notion 10 : `const` — variables et méthodes

**Pourquoi ?** `const` rend une valeur immuable. C'est ce qui fait la différence entre un programme solide et un programme fragile sur le long terme.

**`const` sur un attribut :**
```cpp
class Cercle {
public:
    Cercle(float rayon) : _rayon(rayon), _PI(3.14159f) {}

    float aire() const { return _PI * _rayon * _rayon; }

private:
    float       _rayon;
    float const _PI;   // Ne peut jamais changer après l'initialisation
};
```

**`const` après une méthode :**
```cpp
class Boite {
public:
    Boite(int contenu) : _contenu(contenu) {}

    // Le mot const APRÈS la signature garantit que cette méthode
    // ne modifiera JAMAIS l'instance courante (aucun this->x = ...)
    int getContenu() const {
        return _contenu;      // ✅ Lecture seule : OK
        // _contenu = 0;      // ❌ Ne compilerait pas : méthode const !
    }

    void setContenu(int v) {  // Pas const : modifie l'objet
        _contenu = v;
    }

private:
    int _contenu;
};

int main() {
    const Boite b(42);      // Objet constant : on ne peut appeler que les méthodes const
    std::cout << b.getContenu() << std::endl;  // ✅ méthode const → OK
    // b.setContenu(10);                        // ❌ méthode non-const sur objet const
    return 0;
}
```

> 💡 **Règle pratique :** toute méthode qui ne modifie pas l'objet doit être marquée `const`. C'est un signal clair pour le compilateur ET pour le lecteur du code.

---

### Notion 11 : Visibilité — `public`, `private`, `protected`

**Pourquoi ?** Contrôler qui peut accéder à quoi est fondamental en POO. C'est le mécanisme d'encapsulation.

| Mot-clé | Accessible depuis... |
|---------|---------------------|
| `public` | Partout (l'intérieur et l'extérieur de la classe) |
| `private` | Uniquement depuis les méthodes membres de la classe |
| `protected` | Depuis la classe et ses classes dérivées (héritage) |

**Exemple :**
```cpp
class Coffre {
public:
    Coffre(int code) : _code(code), _ouvert(false) {}

    bool ouvrir(int tentative) {       // public : accessible partout
        if (tentative == _code) {
            _ouvert = true;
            return true;
        }
        return false;
    }

    bool estOuvert() const { return _ouvert; }

private:
    int  _code;    // private : inaccessible depuis l'extérieur
    bool _ouvert;

    void reinitialiser() { _ouvert = false; }  // private : usage interne uniquement
};

int main() {
    Coffre c(1234);
    c.ouvrir(9999);                             // ✅ méthode public
    std::cout << c.estOuvert() << std::endl;    // 0 (false)
    c.ouvrir(1234);
    std::cout << c.estOuvert() << std::endl;    // 1 (true)
    // c._code = 0;         // ❌ Erreur : _code est private
    // c.reinitialiser();   // ❌ Erreur : méthode private
    return 0;
}
```

---

### Notion 12 : Accesseurs (getters & setters)

**Pourquoi ?** Puisque les attributs sont `private`, on ne peut pas y accéder directement depuis l'extérieur. Les **accesseurs** sont de petites méthodes `public` qui servent d'intermédiaires contrôlés — elles peuvent valider les données avant de les accepter.

**Convention de nommage :**
- `get` + nom → lecture (`getAge()`)
- `set` + nom → écriture (`setAge()`)

**Exemple :**
```cpp
class Joueur {
public:
    Joueur(std::string nom) : _nom(nom), _pv(100) {}

    // Getter : lecture seule, donc const
    std::string getNom() const { return _nom; }
    int         getPv()  const { return _pv; }

    // Setter : avec validation des données
    void setPv(int pv) {
        if (pv < 0)
            _pv = 0;       // On ne laisse pas les PV passer en négatif
        else if (pv > 100)
            _pv = 100;     // On plafonne à 100
        else
            _pv = pv;
    }

private:
    std::string _nom;
    int         _pv;
};

int main() {
    Joueur j("Alice");
    std::cout << j.getNom() << " : " << j.getPv() << " PV" << std::endl;
    // "Alice : 100 PV"

    j.setPv(-50);   // La validation empêche les PV négatifs
    std::cout << j.getPv() << std::endl;  // 0

    j.setPv(200);   // Plafonnement à 100
    std::cout << j.getPv() << std::endl;  // 100
    return 0;
}
```

> 💡 L'intérêt du setter n'est pas juste de "mettre une valeur" — c'est de **contrôler** ce qui entre dans l'objet. Sans setter, n'importe qui pourrait mettre n'importe quelle valeur.

---

### Notion 13 : Comparaison entre instances

**Pourquoi ?** On peut écrire des méthodes membres qui **comparent l'instance courante** (`this`) avec une autre instance passée en paramètre. C'est utile pour trier, chercher, ou vérifier une égalité structurelle.

**Exemple :**
```cpp
class Temperature {
public:
    Temperature(float valeur) : _valeur(valeur) {}

    float getValeur() const { return _valeur; }

    // Compare this avec une autre instance
    // Retourne -1, 0 ou 1 (comme strcmp en C)
    int comparer(const Temperature& autre) const {
        if (this->_valeur < autre.getValeur())
            return -1;
        else if (this->_valeur > autre.getValeur())
            return 1;
        return 0;
    }

private:
    float _valeur;
};

int main() {
    Temperature t1(36.6f);
    Temperature t2(39.0f);

    int resultat = t1.comparer(t2);
    if (resultat < 0)
        std::cout << "t1 est plus froide que t2" << std::endl;
    else if (resultat > 0)
        std::cout << "t1 est plus chaude que t2" << std::endl;
    else
        std::cout << "Températures identiques" << std::endl;
    // "t1 est plus froide que t2"
    return 0;
}
```

---

### Notion 14 : Attributs et fonctions non-membres (`static`)

**Pourquoi ?** Un attribut `static` n'appartient **pas à une instance** mais à la **classe entière**. Toutes les instances partagent la même valeur. On ne peut pas utiliser `this` dans une fonction `static` car il n'y a pas d'instance courante.

**Exemple :**
```cpp
class Robot {
public:
    Robot(std::string nom) : _nom(nom) {
        _nbRobots++;  // Incrémenté à chaque création
        std::cout << _nom << " créé. Total : " << _nbRobots << std::endl;
    }

    ~Robot() {
        _nbRobots--;
        std::cout << _nom << " détruit. Total : " << _nbRobots << std::endl;
    }

    // Fonction non-membre (static) : appelable sans instance
    static int getNbRobots() {
        // this->_nom  // ❌ Impossible : pas d'instance courante dans une méthode static
        return _nbRobots;
    }

private:
    std::string      _nom;
    static int       _nbRobots;  // Partagé par tous les objets Robot
};

int Robot::_nbRobots = 0;  // Initialisation obligatoire hors de la classe

int main() {
    std::cout << Robot::getNbRobots() << std::endl;  // 0 (sans instance !)
    {
        Robot r1("R2D2");   // Total : 1
        Robot r2("C3PO");   // Total : 2
        std::cout << Robot::getNbRobots() << std::endl;  // 2
    }  // r1 et r2 détruits ici
    std::cout << Robot::getNbRobots() << std::endl;  // 0
    return 0;
}
```

> 💡 On appelle une méthode statique avec `NomClasse::methode()` et non `instance.methode()`, car elle n'est pas liée à une instance.

---

## Notions clés du module

- `namespace`, `::`
- `std::cout`, `std::cin`, `std::cerr`, `std::endl`, `<<`, `>>`
- `std::string`
- `class`, `struct`, `public`, `private`, `protected`
- Constructeur, destructeur (`~`), instanciation
- `this`
- Liste d'initialisation (`: attribut(valeur)`)
- `const` (attribut et méthode)
- Getter, setter
- `static`
