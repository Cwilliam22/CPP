# Résumé MODULE 01 : Mémoire, références et pointeurs

> Ce module approfondit la gestion de la mémoire : stack vs heap, pointeurs vs références, flux de fichiers, pointeurs de fonctions membres et switch.
> Chaque notion inclut une explication du concept, pourquoi il existe, et un exemple clair pour bien le comprendre.

---

### Notion 1 : Stack vs Heap — les deux zones de mémoire

**Pourquoi ?** En C++, la mémoire est divisée en deux grandes zones. Comprendre leur différence est fondamental pour éviter les fuites mémoire et les comportements indéfinis.

| | Stack (pile) | Heap (tas) |
|---|---|---|
| Allocation | Automatique | Manuelle (`new`) |
| Libération | Automatique (fin de bloc) | Manuelle (`delete`) |
| Taille | Limitée | Très grande |
| Durée de vie | Limitée au bloc `{}` | Jusqu'au `delete` |

**Exemple :**
```cpp
void fonctionStack() {
    int x = 42;       // Alloué sur la STACK
    // x est détruit automatiquement à la fin de cette fonction
}

int* fonctionHeap() {
    int* p = new int(42);  // Alloué sur le HEAP
    return p;              // Survit à la fonction !
}

int main() {
    // Stack : durée de vie limitée au bloc
    {
        int a = 10;   // Créé
    }                 // a détruit ici automatiquement

    // Heap : on contrôle la durée de vie
    int* ptr = fonctionHeap();
    std::cout << *ptr << std::endl;  // 42
    delete ptr;   // On est responsable de libérer
    ptr = NULL;   // Bonne pratique : évite le dangling pointer

    return 0;
}
```

> ⚠️ **Règle absolue :** Tout `new` doit avoir exactement un `delete` correspondant. Sans `delete`, la mémoire est occupée mais inaccessible pour le reste du programme : c'est une **fuite mémoire**.

---

### Notion 2 : `new` et `delete` — allocation dynamique

**Pourquoi ?** `new` et `delete` sont les équivalents C++ de `malloc`/`free` en C, mais en plus sûr : `new` appelle le constructeur, `delete` appelle le destructeur.

**Exemple — objet simple :**
```cpp
class Monstre {
public:
    Monstre(std::string nom) : _nom(nom) {
        std::cout << _nom << " apparaît !" << std::endl;
    }
    ~Monstre() {
        std::cout << _nom << " est vaincu." << std::endl;
    }
private:
    std::string _nom;
};

int main() {
    // new : alloue la mémoire ET appelle le constructeur
    Monstre* m = new Monstre("Goblin");

    // ... utilisation ...

    // delete : appelle le destructeur ET libère la mémoire
    delete m;

    return 0;
}
// Sortie :
// Goblin apparaît !
// Goblin est vaincu.
```

**Exemple — tableau d'objets :**
```cpp
int main() {
    int N = 5;

    // new[] : alloue N objets ET appelle N fois le constructeur
    Monstre* horde = new Monstre[N];

    // ... utilisation ...

    // delete[] : appelle N fois le destructeur ET libère tout
    delete[] horde;   // ⚠️ Les crochets [] sont obligatoires pour un tableau !
    // delete horde;  // ❌ Comportement indéfini : ne détruit qu'un seul objet

    return 0;
}
```

> 💡 **Règle :** `new` → `delete`. `new[]` → `delete[]`. Ne jamais mélanger les deux.

> 💡 **Pourquoi le destructeur n'a pas de paramètre ?** Parce qu'il est appelé automatiquement par le langage — ni l'utilisateur ni `delete` ne lui passe d'argument. Il n'a donc aucune raison d'en accepter.

---

### Notion 3 : Pointeurs vs Références

**Pourquoi ?** Ce sont deux façons d'accéder indirectement à une variable, mais avec des comportements très différents. Bien choisir entre les deux est une question de design.

**La référence** est un **alias** : un autre nom pour la même variable. Elle se comporte exactement comme la variable originale.

**Le pointeur** est une **variable** qui contient une adresse mémoire. On doit le déréférencer (`*`) pour accéder à la valeur.

```
Variable :  [ 42 ]  ← adresse 0x100
Référence : "réf" est juste un autre nom pour 0x100
Pointeur :  [ 0x100 ] ← stocke l'adresse, pas la valeur
```

**Exemple comparatif :**
```cpp
int main() {
    int nombre = 42;

    // Référence : alias, même adresse, même comportement
    int& ref = nombre;    // ref EST nombre (un autre nom)
    ref = 100;            // Modifie nombre directement
    std::cout << nombre << std::endl;  // 100

    // Pointeur : variable stockant une adresse
    int* ptr = &nombre;   // ptr CONTIENT l'adresse de nombre
    *ptr = 200;           // Déréférencement : modifie la valeur à cette adresse
    std::cout << nombre << std::endl;  // 200

    // Preuve qu'ils partagent tous la même adresse
    std::cout << &nombre << std::endl;  // ex: 0x100
    std::cout << &ref    << std::endl;  // ex: 0x100 (identique)
    std::cout << ptr     << std::endl;  // ex: 0x100 (identique)

    return 0;
}
```

**Tableau des différences clés :**

| | Référence (`&`) | Pointeur (`*`) |
|---|---|---|
| Peut être `NULL` | ❌ Non | ✅ Oui |
| Peut changer de cible | ❌ Non (fixée à l'init) | ✅ Oui |
| Doit être initialisée | ✅ Obligatoire | ❌ Non |
| Syntaxe d'accès | Comme la variable normale | `*ptr` ou `ptr->` |
| Arithmétique possible | ❌ Non | ✅ Oui (`ptr++`) |

---

### Notion 4 : Référence vs Pointeur dans les attributs de classe

**Pourquoi ?** Le choix entre référence et pointeur comme attribut d'une classe exprime une **intention de design** : est-ce que cet attribut est obligatoire ou optionnel ?

**Exemple :**
```cpp
class Moteur {
public:
    Moteur(std::string type) : _type(type) {}
    std::string getType() const { return _type; }
private:
    std::string _type;
};

// Voiture A : a TOUJOURS un moteur → référence
// La référence doit être initialisée dans la liste d'initialisation
class VoitureA {
public:
    VoitureA(Moteur& m) : _moteur(m) {}   // Initialisée à la construction
    void demarrer() const {
        std::cout << "Démarre avec moteur : " << _moteur.getType() << std::endl;
    }
private:
    Moteur& _moteur;   // Référence : toujours valide, ne peut pas être NULL
};

// Voiture B : peut exister SANS moteur (en réparation) → pointeur
class VoitureB {
public:
    VoitureB() : _moteur(NULL) {}
    void setMoteur(Moteur& m) { _moteur = &m; }
    void demarrer() const {
        if (_moteur)
            std::cout << "Démarre avec moteur : " << _moteur->getType() << std::endl;
        else
            std::cout << "Pas de moteur !" << std::endl;
    }
private:
    Moteur* _moteur;   // Pointeur : peut être NULL
};

int main() {
    Moteur v8("V8");

    VoitureA a(v8);
    a.demarrer();   // "Démarre avec moteur : V8"

    VoitureB b;
    b.demarrer();   // "Pas de moteur !"
    b.setMoteur(v8);
    b.demarrer();   // "Démarre avec moteur : V8"

    return 0;
}
```

> 💡 **Règle de design :** Si la relation est **obligatoire et permanente** → référence. Si elle est **optionnelle ou peut changer** → pointeur.

> 💡 **Pourquoi la liste d'initialisation est obligatoire pour une référence attribut ?** Parce qu'une référence doit être liée à sa cible dès sa création. On ne peut pas d'abord créer l'objet puis affecter la référence ensuite dans le corps du constructeur.

---

### Notion 5 : Flux de fichiers (`fstream`)

**Pourquoi ?** La bibliothèque `<fstream>` permet de lire et écrire dans des fichiers exactement comme on utilise `std::cout` et `std::cin`, avec le même système de flux `<<` et `>>`.

**Les trois classes de `<fstream>` :**

| Classe | Usage |
|--------|-------|
| `std::ofstream` | Créer et écrire dans un fichier |
| `std::ifstream` | Lire depuis un fichier |
| `std::fstream` | Lire ET écrire (combinaison des deux) |

**Fonctions essentielles :**

| Fonction | Rôle |
|----------|------|
| `open("nom")` | Ouvre un fichier |
| `is_open()` | Vérifie si le fichier est bien ouvert |
| `getline(flux, ligne)` | Lit une ligne complète |
| `close()` | Ferme le fichier |
| `find(s, pos)` | Cherche une sous-chaîne |
| `insert(pos, s)` | Insère une chaîne à une position |
| `erase(pos, len)` | Supprime des caractères |

**Exemple complet :**
```cpp
#include <fstream>
#include <iostream>
#include <string>

int main() {
    // ── Écriture ────────────────────────────────────────
    std::ofstream fichierEcriture("journal.txt");
    if (!fichierEcriture.is_open()) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier en écriture" << std::endl;
        return 1;
    }
    fichierEcriture << "Ligne 1 : Bonjour" << std::endl;
    fichierEcriture << "Ligne 2 : Au revoir" << std::endl;
    fichierEcriture.close();

    // ── Lecture ligne par ligne ──────────────────────────
    std::ifstream fichierLecture("journal.txt");
    if (!fichierLecture.is_open()) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier en lecture" << std::endl;
        return 1;
    }
    std::string ligne;
    while (std::getline(fichierLecture, ligne))
        std::cout << ligne << std::endl;
    fichierLecture.close();

    return 0;
}
```

> 💡 **Toujours** vérifier `is_open()` avant d'utiliser un flux de fichier. Un fichier peut ne pas exister, être protégé en écriture, ou le chemin peut être incorrect.

> ⚠️ **`const` après une fonction libre ?** Non — le mot-clé `const` après la signature n'est valide que pour les **méthodes membres** d'une classe (il s'applique à `this`). Une fonction libre n'a pas de `this`, donc `const` n'y a pas de sens.

---

### Notion 6 : Pointeurs sur fonctions

**Pourquoi ?** Chaque fonction a une adresse en mémoire, comme une variable. On peut stocker cette adresse dans un pointeur et appeler la fonction via ce pointeur. Cela permet de choisir dynamiquement quelle fonction appeler.

**Exemple — pointeur sur fonction libre :**
```cpp
int addition(int a, int b)       { return a + b; }
int soustraction(int a, int b)   { return a - b; }
int multiplication(int a, int b) { return a * b; }

int main() {
    // Déclaration : int (*nomPointeur)(int, int)
    //               ^type retour  ^paramètres
    int (*operation)(int, int);

    operation = &addition;         // Liaison (& optionnel)
    std::cout << operation(3, 4) << std::endl;  // 7

    operation = &soustraction;
    std::cout << operation(10, 3) << std::endl;  // 7

    // Tableau de pointeurs sur fonctions
    int (*ops[3])(int, int) = {&addition, &soustraction, &multiplication};
    for (int i = 0; i < 3; i++)
        std::cout << ops[i](6, 2) << std::endl;  // 8, 4, 12

    return 0;
}
```

**Pointeur sur méthode membre :**

La syntaxe est légèrement différente car la méthode appartient à une classe — il faut préciser cette classe avec `::*`.

```cpp
class Harl {
public:
    void debug()   { std::cout << "[DEBUG]"   << std::endl; }
    void info()    { std::cout << "[INFO]"    << std::endl; }
    void warning() { std::cout << "[WARNING]" << std::endl; }
    void error()   { std::cout << "[ERROR]"   << std::endl; }

    void complain(std::string niveau) {
        std::string niveaux[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

        // void (Harl::*f)() = pointeur vers une méthode de Harl sans paramètre
        void (Harl::*fonctions[4])() = {
            &Harl::debug, &Harl::info, &Harl::warning, &Harl::error
        };

        for (int i = 0; i < 4; i++) {
            if (niveau == niveaux[i]) {
                (this->*fonctions[i])();  // Appel via le pointeur sur méthode
                return;
            }
        }
        std::cout << "Niveau inconnu." << std::endl;
    }
};

int main() {
    Harl h;
    h.complain("WARNING");  // [WARNING]
    h.complain("DEBUG");    // [DEBUG]
    return 0;
}
```

> 💡 **Syntaxe à retenir :**
> - Pointeur sur fonction libre : `type_retour (*nom)(params)`
> - Pointeur sur méthode membre : `type_retour (Classe::*nom)(params)`
> - Appel via pointeur membre : `(objet.*pointeur)(args)` ou `(ptr->*pointeur)(args)`

---

### Notion 7 : `switch` et fall-through

**Pourquoi ?** Le `switch` est une alternative aux longues chaînes `if / else if` quand on teste une variable entière contre plusieurs valeurs fixes. Il est plus lisible et souvent plus performant.

**Syntaxe de base :**
```cpp
int choix = 2;

switch (choix) {       // switch ne prend qu'un entier (ou char)
    case 1:
        std::cout << "Option 1" << std::endl;
        break;         // Stoppe l'exécution du switch
    case 2:
        std::cout << "Option 2" << std::endl;
        break;
    case 3:
        std::cout << "Option 3" << std::endl;
        break;
    default:           // Exécuté si aucun case ne correspond
        std::cout << "Option inconnue" << std::endl;
}
// Affiche : "Option 2"
```

**Le fall-through — intentionnel ou piège :**

Sans `break`, l'exécution **continue dans le case suivant** automatiquement. C'est le **fall-through**. Il peut être un bug ou un comportement voulu.

```cpp
// ❌ Fall-through INVOLONTAIRE (bug classique)
int note = 2;
switch (note) {
    case 1: std::cout << "Très bien" << std::endl;   // Oubli de break !
    case 2: std::cout << "Bien" << std::endl;         // Oubli de break !
    case 3: std::cout << "Passable" << std::endl;
        break;
}
// Si note == 1 : affiche "Très bien", "Bien", "Passable" → non voulu !

// ✅ Fall-through INTENTIONNEL (comportement voulu)
// Système de log cumulatif : chaque niveau affiche aussi les suivants
void afficherDepuis(int niveau) {
    switch (niveau) {
        case 1:
            std::cout << "[INFO] Tout va bien." << std::endl;
            // Pas de break → tombe intentionnellement dans case 2
        case 2:
            std::cout << "[WARNING] Soyez attentif." << std::endl;
        case 3:
            std::cout << "[ERROR] Problème critique !" << std::endl;
            break;
        default:
            std::cout << "Niveau inconnu." << std::endl;
    }
}

int main() {
    afficherDepuis(1);  // Affiche INFO + WARNING + ERROR
    std::cout << "---" << std::endl;
    afficherDepuis(2);  // Affiche WARNING + ERROR
    afficherDepuis(3);  // Affiche ERROR seulement
    return 0;
}
```

> 💡 **Avantages du switch sur if/else :**
> - Meilleure lisibilité quand le nombre de cas est élevé
> - Les options sont mutuellement exclusives et clairement délimitées
> - Le compilateur peut optimiser un switch en table de saut

> ⚠️ **Limitation :** `switch` ne fonctionne qu'avec des types entiers (`int`, `char`, `enum`). Impossible de switcher directement sur une `std::string`.

---

## Notions clés

- `new`, `delete`, `new[]`, `delete[]`
- Stack (pile) vs Heap (tas)
- Fuite mémoire, destructeur sans paramètre
- `&` (référence / alias), `*` (pointeur / déréférencement)
- Référence attribut (obligatoire) vs Pointeur attribut (optionnel)
- `std::ifstream`, `std::ofstream`, `std::fstream`
- `is_open()`, `getline()`, `open()`, `close()`
- Pointeur sur fonction libre : `type (*nom)(params)`
- Pointeur sur méthode membre : `type (Classe::*nom)(params)`
- `switch`, `case`, `break`, `default`, fall-through
