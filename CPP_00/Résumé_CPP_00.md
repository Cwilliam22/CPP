# Résumé pédagogique — MODULE 00 : Introduction à la POO et aux classes

> Ce module est le point d'entrée dans la programmation orientée objet (POO) en C++.
> Chaque notion inclut une explication du concept, pourquoi il existe, et un exemple clair pour bien le comprendre.

---

### Notion 1 : `std::string` et manipulation de chaînes

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

### Notion 2 : Les classes — définition et encapsulation

**Pourquoi ?** Une classe regroupe des **données** (attributs) et des **comportements** (méthodes) dans un seul objet. L'encapsulation protège les données internes via `private`.

**Exemple :**
```cpp
class Voiture {
public:
    // Méthodes accessibles depuis l'extérieur
    void setVitesse(int v) { _vitesse = v; }
    int  getVitesse() const { return _vitesse; }
    void afficher() const {
        std::cout << "Vitesse : " << _vitesse << " km/h" << std::endl;
    }

private:
    // Données protégées : on ne peut pas les modifier directement
    int _vitesse;
};

int main() {
    Voiture v;
    v.setVitesse(130);
    v.afficher();        // "Vitesse : 130 km/h"
    // v._vitesse = 200; // ❌ Erreur de compilation ! _vitesse est privé
    return 0;
}
```

> 💡 **Règle générale :** Les attributs sont `private`, les méthodes d'accès sont `public`. On ne laisse jamais l'extérieur modifier directement l'état interne d'un objet.

---

### Notion 3 : Constructeur et destructeur

**Pourquoi ?** Le constructeur initialise l'objet à sa création. Le destructeur libère les ressources à sa destruction. En C++, cela est **automatique** selon la durée de vie de l'objet.

**Exemple :**
```cpp
class Lampe {
public:
    Lampe(std::string couleur) : _couleur(couleur) {
        std::cout << "Lampe " << _couleur << " allumée !" << std::endl;
    }

    ~Lampe() {
        std::cout << "Lampe " << _couleur << " éteinte." << std::endl;
    }

private:
    std::string _couleur;
};

int main() {
    Lampe rouge("rouge");   // → "Lampe rouge allumée !"
    {
        Lampe bleue("bleue"); // → "Lampe bleue allumée !"
    }                         // → "Lampe bleue éteinte." (fin du bloc)
    return 0;
}                             // → "Lampe rouge éteinte." (fin du main)
```
Le destructeur est appelé **automatiquement** dès que l'objet sort de sa portée.

---

### Notion 4 : Variables et méthodes statiques

**Pourquoi ?** Une variable `static` appartient à **la classe entière**, pas à une instance particulière. Elle est partagée par tous les objets.

**Exemple :**
```cpp
class Compteur {
public:
    Compteur() { _total++; }
    ~Compteur() { _total--; }

    static int getTotal() { return _total; }

private:
    static int _total;  // Partagé par TOUS les objets Compteur
};

int Compteur::_total = 0;  // Initialisation hors de la classe

int main() {
    std::cout << Compteur::getTotal() << std::endl;  // 0
    Compteur a;
    Compteur b;
    std::cout << Compteur::getTotal() << std::endl;  // 2
    {
        Compteur c;
        std::cout << Compteur::getTotal() << std::endl;  // 3
    }
    std::cout << Compteur::getTotal() << std::endl;  // 2 (c détruit)
    return 0;
}
```

> 💡 **Analogie :** Chaque élève d'une école a son propre nom (attribut d'instance), mais le nombre total d'élèves appartient à l'école entière (attribut statique).

---

## 🔑 Mots-clés du module

- `class`, `public`, `private`
- `std::string`, `std::cout`
- Constructeur, destructeur (`~`)
- Getter, setter
- `static`
