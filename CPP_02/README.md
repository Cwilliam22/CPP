# Résumé MODULE 02 : Forme Canonique Orthodoxe et surcharge d'opérateurs

> Ce module introduit la forme canonique orthodoxe (OCF), les nombres à virgule fixe, et la surcharge d'opérateurs.
> Chaque notion inclut une explication du concept, pourquoi il existe, et un exemple clair pour bien le comprendre.

---

### Notion 1 : La Forme Canonique Orthodoxe (Orthodox Canonical Form)

**Pourquoi ?** Toute classe qui gère des ressources (mémoire dynamique, fichiers, connexions…) doit implémenter ces éléments pour se comporter correctement lors des copies et destructions. Sans eux, les copies produisent des comportements indéfinis.

**Les 4 éléments obligatoires :**

```cpp
class Sample {
public:
    Sample();                               // 1. Constructeur par défaut
    Sample(const Sample& other);            // 2. Constructeur de copie
    Sample& operator=(const Sample& other); // 3. Opérateur d'affectation
    ~Sample();                              // 4. Destructeur
};
```

---

**1. Constructeur par défaut**

Initialise l'objet avec des valeurs par défaut quand aucun argument n'est fourni.

```cpp
class Joueur {
public:
    Joueur() : _nom("Inconnu"), _score(0) {
        std::cout << "Joueur créé (défaut)" << std::endl;
    }
private:
    std::string _nom;
    int         _score;
};

int main() {
    Joueur j;   // Appelle le constructeur par défaut
    return 0;
}
```

---

**2. Constructeur paramétré**

Initialise l'objet avec des valeurs spécifiques fournies en arguments. Ce n'est pas l'un des 4 éléments obligatoires de l'OCF, mais il complète naturellement le constructeur par défaut.

```cpp
class Joueur {
public:
    Joueur(const std::string& nom, int score) : _nom(nom), _score(score) {
        std::cout << "Joueur créé : " << _nom << std::endl;
    }
private:
    std::string _nom;
    int         _score;
};

int main() {
    Joueur j("Alice", 100);   // Appelle le constructeur paramétré
    return 0;
}
```

---

**3. Constructeur de copie**

Crée un **nouvel objet** à partir d'un objet existant. Il est appelé lors de la création d'un objet par copie.

```cpp
// Signature type : MaClasse(const MaClasse& other)
//  - const : on ne modifie pas l'objet source
//  - & : on passe par référence pour éviter un appel récursif infini
//        (si on passait par valeur, copier l'argument appellerait le constructeur de copie...)

class Joueur {
public:
    Joueur(const Joueur& other) : _nom(other._nom), _score(other._score) {
        std::cout << "Joueur copié : " << _nom << std::endl;
    }
private:
    std::string _nom;
    int         _score;
};

int main() {
    Joueur j1("Alice", 100);
    Joueur j2(j1);   // Appelle le constructeur de copie
    Joueur j3 = j1;  // Aussi le constructeur de copie (j3 n'existe pas encore)
    return 0;
}
```

---

**4. Opérateur d'affectation**

Copie le contenu d'un objet **existant** dans un autre objet **existant**. Deux points critiques : gérer l'auto-affectation (`a = a`) et retourner `*this` pour permettre le chaînage (`a = b = c`).

```cpp
class Joueur {
public:
    Joueur& operator=(const Joueur& other) {
        if (this != &other) {   // Garde contre l'auto-affectation
            _nom   = other._nom;
            _score = other._score;
        }
        return (*this);   // Retourner *this permet : j1 = j2 = j3
    }
private:
    std::string _nom;
    int         _score;
};

int main() {
    Joueur j1("Alice", 100);
    Joueur j2("Bob", 50);
    j2 = j1;   // Appelle l'opérateur d'affectation (j2 existait déjà)
    return 0;
}
```

> 💡 **Différence constructeur de copie vs opérateur d'affectation :**
> - `Joueur j2(j1)` ou `Joueur j2 = j1` → constructeur de copie (`j2` n'existe pas encore)
> - `j2 = j1` → opérateur d'affectation (`j2` existe déjà, on remplace son contenu)

---

**5. Destructeur**

Appelé automatiquement quand l'objet sort de portée ou est `delete`'d. Sert à libérer les ressources acquises (mémoire dynamique, fichiers ouverts, etc.).

```cpp
class Joueur {
public:
    Joueur(const std::string& nom) {
        _nom = new std::string(nom);   // Allocation dynamique
    }

    ~Joueur() {
        std::cout << "Destruction de " << *_nom << std::endl;
        delete _nom;   // Libération obligatoire
    }
private:
    std::string* _nom;
};
```

---

**Exemple complet OCF :**

```cpp
class Boite {
public:
    Boite() : _contenu(new std::string("vide")) {
        std::cout << "Constructeur par défaut" << std::endl;
    }

    Boite(const Boite& other) : _contenu(new std::string(*other._contenu)) {
        std::cout << "Constructeur de copie" << std::endl;
    }

    Boite& operator=(const Boite& other) {
        if (this != &other) {
            delete _contenu;
            _contenu = new std::string(*other._contenu);
        }
        return (*this);
    }

    ~Boite() {
        std::cout << "Destructeur" << std::endl;
        delete _contenu;
    }

private:
    std::string* _contenu;
};

int main() {
    Boite a;          // Constructeur par défaut
    Boite b(a);       // Constructeur de copie
    Boite c;
    c = a;            // Opérateur d'affectation
    return 0;         // 3 × Destructeur
}
```

---

### Notion 2 : Nombres à virgule fixe (Fixed-point numbers)

**Pourquoi ?** Les `float` et `double` sont des nombres à **virgule flottante** : leur précision varie selon la magnitude du nombre, ce qui peut causer des imprécisions. Les nombres à **virgule fixe** représentent toujours les entiers et les décimaux avec la même précision, en stockant tout sous forme d'entier avec un facteur d'échelle fixe.

**Le principe — déplacer le point binaire :**

En binaire, décaler le point vers la gauche divise par 2, vers la droite multiplie par 2.

```
53  en binaire :  1 1 0 1 0 1 . 0 0 0
26.5 en binaire : 0 1 1 0 1 0 . 1 0 0
                              ^
                        Point binaire
```

**La notation `fixe<w, b>` :**
- `w` = nombre total de bits (largeur)
- `b` = nombre de bits réservés à la partie fractionnaire (à droite du point)

```
Exemple : fixe<8, 3>
Représentation :  0 0 0 1 0 . 1 1 0
                             ^
                       3 bits fractionnaires

= 1×2¹ + 0×2⁰ + 1×2⁻¹ + 1×2⁻²
= 2 + 0 + 0.5 + 0.25
= 2.75
```

**La formule clé :**
```
Nombre réel   = entier_stocké / 2^fractionalBits
Entier_stocké = nombre_réel   × 2^fractionalBits
```

**Le bit-shifting — une multiplication/division rapide par 2 :**
```cpp
x << 1   // x × 2
x << n   // x × 2^n  (équivalent de × 256 si n = 8)
x >> n   // x / 2^n
```

**Implémentation en C++ :**
```cpp
#include <cmath>   // pour roundf()

class Fixed {
public:
    Fixed() : _valeur(0) {}

    // Convertir un entier : décaler les bits vers la gauche
    Fixed(const int n) : _valeur(n << _bits) {}

    // Convertir un float : multiplier et arrondir à l'entier le plus proche
    // roundf() renvoie le float arrondi à l'entier le plus proche
    Fixed(const float f) : _valeur(roundf(f * (1 << _bits))) {}

    // Récupérer la valeur entière : décaler vers la droite
    int   toInt()   const { return (_valeur >> _bits); }

    // Récupérer la valeur flottante : diviser par 2^bits
    float toFloat() const { return (_valeur / (float)(1 << _bits)); }

private:
    int              _valeur;
    static const int _bits = 8;   // 8 bits fractionnaires → précision 1/256 ≈ 0.0039
};

int main() {
    Fixed a(10);       // Entier 10  → stocké comme 10 × 256 = 2560
    Fixed b(3.14f);    // Float 3.14 → stocké comme round(3.14 × 256) = 804

    std::cout << a.toFloat() << std::endl;  // 10
    std::cout << b.toFloat() << std::endl;  // 3.14063 (approximation)
    return 0;
}
```

**Nombres négatifs — le complément à deux :**

En binaire, les nombres négatifs sont représentés par le **complément à deux** :
```
Exemple : -6 sur 4 bits
  Positif de 6 :  0 1 1 0
  Inverser bits :  1 0 0 1
  Ajouter 1 :      1 0 1 0  → -6

Lecture inverse :
  1 0 1 0  → le bit de gauche est 1 → nombre négatif
  Inverser : 0 1 0 1
  Ajouter 1 : 0 1 1 0 → 6
  Donc 1010 = -6
```

---

### Notion 3 : Surcharge d'opérateurs

**Pourquoi ?** Les opérateurs (`+`, `-`, `<<`, `==`, etc.) sont en réalité des **fonctions**. On peut redéfinir leur comportement pour nos propres types, rendant le code plus naturel et lisible.

> 💡 **Principe :** `a + b` est un raccourci pour `operator+(a, b)`. On dit au compilateur comment utiliser cet opérateur avec un nouveau type.

---

**Surcharge de `<<` (opérateur d'insertion)**

Sans cette surcharge, `std::cout << monObjet` ne compile pas : le compilateur ne sait pas comment afficher un type personnalisé.

```cpp
class Fixed {
public:
    Fixed(float f) : _valeur(roundf(f * 256)) {}
    float toFloat() const { return _valeur / 256.0f; }
private:
    int _valeur;
};

// Se déclare en dehors de la classe (fonction libre)
// Retourne ostream& pour permettre le chaînage : cout << a << b
std::ostream& operator<<(std::ostream& os, const Fixed& f) {
    os << f.toFloat();
    return os;
}

int main() {
    Fixed f(3.14f);
    std::cout << f << std::endl;           // "3.14063"
    std::cout << f << " et " << f << std::endl;  // Chaînage possible
    return 0;
}
```

---

**Opérateurs de comparaison :**

```cpp
class Temperature {
public:
    Temperature(float v) : _val(v) {}

    bool operator>(const Temperature& other)  const { return _val > other._val; }
    bool operator<(const Temperature& other)  const { return _val < other._val; }
    bool operator>=(const Temperature& other) const { return _val >= other._val; }
    bool operator<=(const Temperature& other) const { return _val <= other._val; }
    bool operator==(const Temperature& other) const { return _val == other._val; }
    bool operator!=(const Temperature& other) const { return _val != other._val; }

private:
    float _val;
};

int main() {
    Temperature t1(36.6f), t2(39.0f);
    std::cout << (t1 < t2)  << std::endl;  // 1 (true)
    std::cout << (t1 == t2) << std::endl;  // 0 (false)
    return 0;
}
```

---

**Opérateurs arithmétiques :**

```cpp
class Fixed {
public:
    Fixed(float f) : _valeur(roundf(f * (1 << 8))) {}

    Fixed operator+(const Fixed& other) const {
        Fixed result(0.0f);
        result._valeur = _valeur + other._valeur;  // Addition directe sur les entiers
        return result;
    }

    Fixed operator-(const Fixed& other) const {
        Fixed result(0.0f);
        result._valeur = _valeur - other._valeur;
        return result;
    }

    Fixed operator*(const Fixed& other) const {
        Fixed result(0.0f);
        // La multiplication double le décalage → on compense en décalant d'un _bits
        result._valeur = (_valeur * other._valeur) >> 8;
        return result;
    }

    Fixed operator/(const Fixed& other) const {
        Fixed result(0.0f);
        // La division inverse → on décale d'abord avant de diviser
        result._valeur = (_valeur << 8) / other._valeur;
        return result;
    }

private:
    int _valeur;
    static const int _bits = 8;
};
```

---

**Opérateurs d'incrémentation — pré vs post :**

```cpp
class Compteur {
public:
    Compteur(int v) : _val(v) {}
    int getVal() const { return _val; }

    // Pré-incrément (++c) : incrémente PUIS retourne la nouvelle valeur
    Compteur& operator++() {
        _val++;
        return (*this);   // Retourne l'objet modifié
    }

    // Post-incrément (c++) : sauvegarde, incrémente, retourne L'ANCIENNE valeur
    // Le paramètre int (muet) distingue la signature du pré-incrément
    Compteur operator++(int) {
        Compteur ancien = *this;  // Copie avant modification
        _val++;
        return ancien;            // Retourne la copie (avant modification)
    }

    // Même logique pour -- (pré et post décrément)
    Compteur& operator--()    { _val--; return (*this); }
    Compteur  operator--(int) { Compteur old = *this; _val--; return old; }

private:
    int _val;
};

int main() {
    Compteur c(5);
    std::cout << (++c).getVal() << std::endl;  // 6  (pré : incrémente d'abord)
    std::cout << (c++).getVal() << std::endl;  // 6  (post : retourne AVANT l'incrément)
    std::cout << c.getVal()     << std::endl;  // 7  (c vaut bien 7 maintenant)
    return 0;
}
```

> 💡 **Pourquoi le post-incrément est moins efficace ?** Il crée une copie temporaire de l'objet (pour retourner l'ancienne valeur), alors que le pré-incrément retourne directement `*this`. Pour les types simples c'est négligeable, mais pour les objets complexes, préférer `++i` à `i++` quand le résultat n'est pas utilisé.

---

**Fonctions statiques surchargées — `min` et `max` :**

```cpp
class Fixed {
public:
    Fixed(float f) : _valeur(roundf(f * 256)) {}
    bool operator<(const Fixed& other) const { return _valeur < other._valeur; }
    bool operator>(const Fixed& other) const { return _valeur > other._valeur; }

    // Version pour objets modifiables
    static Fixed& min(Fixed& a, Fixed& b)             { return (a < b) ? a : b; }
    static Fixed& max(Fixed& a, Fixed& b)             { return (a > b) ? a : b; }

    // Version pour objets constants (const)
    static const Fixed& min(const Fixed& a, const Fixed& b) { return (a < b) ? a : b; }
    static const Fixed& max(const Fixed& a, const Fixed& b) { return (a > b) ? a : b; }

private:
    int _valeur;
};

int main() {
    Fixed a(3.5f), b(1.2f);
    std::cout << Fixed::min(a, b).toFloat() << std::endl;  // 1.2
    std::cout << Fixed::max(a, b).toFloat() << std::endl;  // 3.5
    return 0;
}
```

> 💡 **Pourquoi deux versions (const et non-const) ?** Une fonction non-`const` ne peut pas être appelée sur un objet constant. Avoir les deux versions permet d'utiliser `min`/`max` dans tous les contextes.

---

### Notion 4 : Application — BSP (Binary Space Partitioning)

**Pourquoi ?** Le BSP est un algorithme géométrique qui détermine si un point se trouve à l'intérieur d'un triangle. C'est une belle application concrète de la classe `Fixed` avec ses opérateurs.

**Principe :**

Pour chaque côté du triangle (formé par deux sommets), on calcule de quel côté se trouve le point à tester. Si le point est du même côté pour les trois arêtes, il est à l'intérieur.

```
   A
  / \
 /   \
B-----C
```

On calcule l'**aire signée** du parallélogramme formé par deux points du triangle et le point à tester. Le **signe** de cette aire indique le côté :
- Aire > 0 → point à droite de l'arête
- Aire < 0 → point à gauche de l'arête
- Aire = 0 → point exactement sur l'arête (donc pas strictement à l'intérieur)

**Formule du déterminant (aire signée) :**
```
aire(P1, P2, P) = (x1)(y2 - yP) + (x2)(yP - y1) + (xP)(y1 - y2)
```

**Implémentation :**
```cpp
bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed aire_ab = calculerAire(a, b, point);
    Fixed aire_bc = calculerAire(b, c, point);
    Fixed aire_ca = calculerAire(c, a, point);

    // Point sur une arête → pas strictement à l'intérieur
    if (aire_ab == 0 || aire_bc == 0 || aire_ca == 0)
        return false;

    // Tous du même signe → à l'intérieur
    if (aire_ab > 0 && aire_bc > 0 && aire_ca > 0)
        return true;
    if (aire_ab < 0 && aire_bc < 0 && aire_ca < 0)
        return true;

    return false;
}
```

---

## Notions clés

- OCF : constructeur par défaut, constructeur de copie, opérateur d'affectation, destructeur
- Constructeur paramétré (complément naturel de l'OCF)
- `const MaClasse& other` dans le constructeur de copie (évite la récursion infinie)
- Auto-affectation (`if (this != &other)`) dans l'opérateur d'affectation
- Retourner `*this` pour permettre le chaînage
- Virgule fixe : `entier_stocké = valeur_réelle × 2^bits`
- Bit-shifting : `<<` (multiplie par 2^n), `>>` (divise par 2^n)
- `roundf()` — arrondi flottant (`#include <cmath>`)
- Complément à deux — représentation des négatifs en binaire
- Surcharge de `<<` — fonction libre retournant `std::ostream&`
- Opérateurs de comparaison, arithmétiques, incrémentation (pré vs post)
- Pré-incrément (`++c`) retourne `*this`, post-incrément (`c++`) retourne une copie
- `static min/max` — deux versions (const et non-const)
- BSP — aire signée et déterminant pour tester l'appartenance à un triangle
