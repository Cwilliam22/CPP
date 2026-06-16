# Résumé MODULE 03 : Héritage

> Ce module introduit l'héritage en C++ : comment une classe peut hériter d'une autre, les différents types de visibilité, l'ordre de construction/destruction, et les problèmes liés à l'héritage multiple.
> Chaque notion inclut une explication du concept, pourquoi il existe, et un exemple clair pour bien le comprendre.

---

### Notion 1 : Qu'est-ce que l'héritage ?

**Pourquoi ?** L'héritage permet à une classe (la **classe fille** ou **dérivée**) d'hériter automatiquement de tous les attributs et méthodes d'une autre classe (la **classe mère** ou **de base**). Cela évite de réécrire du code commun et permet de spécialiser un comportement existant.

**Vocabulaire :**
- Classe mère = classe de base = classe antécédente = classe parent
- Classe fille = classe dérivée = classe descendante = classe enfant

**Analogie :** Un `Chien` EST un `Animal`. Il hérite de toutes les caractéristiques d'un animal (respirer, manger…) et y ajoute les siennes propres (aboyer).

**Syntaxe :**
```cpp
class ClasseMere {
    /* contenu de la classe mère */
};

class ClasseFille : public ClasseMere {
    /* la classe fille hérite de tout ce qui est accessible dans ClasseMere */
    /* et peut y ajouter ses propres attributs et méthodes */
};
```

**Exemple :**
```cpp
class Animal {
public:
    Animal(std::string nom) : _nom(nom) {}
    void respirer() const {
        std::cout << _nom << " respire." << std::endl;
    }
protected:
    std::string _nom;   // protected : accessible par les classes filles
};

class Chien : public Animal {
public:
    Chien(std::string nom) : Animal(nom) {}  // Appel du constructeur parent
    void aboyer() const {
        std::cout << _nom << " : Wouf !" << std::endl;
    }
};

int main() {
    Chien rex("Rex");
    rex.respirer();   // ✅ Hérité de Animal
    rex.aboyer();     // ✅ Propre à Chien
    return 0;
}
```

---

### Notion 2 : Les trois types d'héritage — `public`, `protected`, `private`

**Pourquoi ?** Le modificateur d'héritage contrôle comment la **visibilité** des membres de la classe mère est perçue depuis la classe fille et depuis l'extérieur.

| Membre dans la mère | Héritage `public` | Héritage `protected` | Héritage `private` |
|---------------------|-------------------|----------------------|--------------------|
| `public`            | `public`          | `protected`          | `private`          |
| `protected`         | `protected`       | `protected`          | `private`          |
| `private`           | inaccessible      | inaccessible         | inaccessible       |

> 💡 **Dans la pratique**, l'héritage `public` est de loin le plus utilisé — il préserve la visibilité originale et est le seul qui modélise correctement la relation "est un" (un `Chien` EST un `Animal`).

**Exemple :**
```cpp
class Base {
public:
    int pub;
protected:
    int prot;
private:
    int priv;
};

// Héritage public : pub reste public, prot reste protected
class FillePublique : public Base {
    void test() {
        pub  = 1;   // ✅ public → reste public
        prot = 2;   // ✅ protected → reste protected
        // priv = 3; // ❌ private → toujours inaccessible
    }
};

// Héritage protected : pub ET prot deviennent tous les deux protected
class FilleProtegee : protected Base {
    void test() {
        pub  = 1;   // ✅ public → devient protected
        prot = 2;   // ✅ protected → reste protected
    }
};

// Héritage private : pub ET prot deviennent tous les deux private
class FillePrivee : private Base {
    void test() {
        pub  = 1;   // ✅ public → devient private
        prot = 2;   // ✅ protected → devient private
    }
};

int main() {
    FillePublique fp;
    fp.pub = 10;     // ✅ encore public depuis l'extérieur

    FilleProtegee fpr;
    // fpr.pub = 10; // ❌ pub est devenu protected, inaccessible depuis l'extérieur

    FillePrivee fpriv;
    // fpriv.pub = 10; // ❌ pub est devenu private, inaccessible depuis l'extérieur
    return 0;
}
```

---

### Notion 3 : `protected` — le troisième niveau de visibilité

**Pourquoi ?** `protected` est un niveau intermédiaire entre `public` et `private`, conçu spécifiquement pour l'héritage. Un membre `protected` est inaccessible depuis l'extérieur, mais accessible depuis les classes filles.

```
private   → accessible uniquement dans la classe elle-même
protected → accessible dans la classe ET dans ses classes filles
public    → accessible partout
```

**Exemple :**
```cpp
class Vehicule {
protected:
    int _vitesseMax;   // Accessible par les classes filles, pas depuis l'extérieur
public:
    Vehicule(int vMax) : _vitesseMax(vMax) {}
};

class Voiture : public Vehicule {
public:
    Voiture(int vMax) : Vehicule(vMax) {}

    void afficherVitesse() const {
        // ✅ _vitesseMax est protected → accessible ici
        std::cout << "Vitesse max : " << _vitesseMax << " km/h" << std::endl;
    }
};

int main() {
    Voiture v(200);
    v.afficherVitesse();    // ✅ méthode public
    // v._vitesseMax = 300; // ❌ protected → inaccessible depuis l'extérieur
    return 0;
}
```

---

### Notion 4 : Ordre de construction et de destruction

**Pourquoi ?** La classe fille **dépend** de la classe mère — elle ne peut pas exister sans que la mère soit correctement initialisée. Le langage impose donc un ordre précis.

**Règle :**
- **Construction** : Parent → Enfant (la mère est construite en premier)
- **Destruction** : Enfant → Parent (la fille est détruite en premier)

**Comment appeler le constructeur parent :**
```cpp
ClasseFille::ClasseFille(params) : ClasseMere(params_pour_mere) {
    // Corps du constructeur de la fille
}
```

**Exemple :**
```cpp
class Base {
public:
    Base()  { std::cout << "Base construite"  << std::endl; }
    ~Base() { std::cout << "Base détruite"    << std::endl; }
};

class Milieu : public Base {
public:
    Milieu()  : Base() { std::cout << "Milieu construit"  << std::endl; }
    ~Milieu()          { std::cout << "Milieu détruit"    << std::endl; }
};

class Fille : public Milieu {
public:
    Fille()  : Milieu() { std::cout << "Fille construite"  << std::endl; }
    ~Fille()            { std::cout << "Fille détruite"    << std::endl; }
};

int main() {
    Fille f;
    return 0;
}
// Sortie :
// Base construite     ← Grand-parent d'abord
// Milieu construit    ← Puis parent
// Fille construite    ← Puis enfant
// Fille détruite      ← Enfant détruit en premier
// Milieu détruit
// Base détruite       ← Grand-parent détruit en dernier
```

> 💡 **Pourquoi cet ordre ?** À la construction, la fille peut avoir besoin de données initialisées par la mère. À la destruction, si on détruisait la mère en premier, la fille tenterait d'accéder à des données invalides.

---

### Notion 5 : Redéfinition de méthodes (override)

**Pourquoi ?** Une classe fille peut **redéfinir** une méthode héritée pour lui donner un comportement différent. La version appelée dépend du type de l'objet.

```cpp
class ClapTrap {
public:
    ClapTrap(std::string nom) : _nom(nom), _pv(10), _energie(10), _degats(0) {}

    // Méthode que ScavTrap va redéfinir
    void attack(const std::string& cible) {
        std::cout << "ClapTrap " << _nom << " attaque " << cible
                  << " pour " << _degats << " dégâts !" << std::endl;
        _energie--;
    }

protected:
    std::string _nom;
    int         _pv;
    int         _energie;
    int         _degats;
};

class ScavTrap : public ClapTrap {
public:
    ScavTrap(std::string nom) : ClapTrap(nom) {
        _pv      = 100;   // Redéfinit les valeurs initiales
        _energie = 50;
        _degats  = 20;
    }

    // Redéfinition de attack() : comportement différent de ClapTrap
    void attack(const std::string& cible) {
        std::cout << "ScavTrap " << _nom << " attaque férocement " << cible
                  << " pour " << _degats << " dégâts !" << std::endl;
        _energie--;
    }

    // Méthode propre à ScavTrap
    void guardGate() {
        std::cout << _nom << " est maintenant en mode gardien !" << std::endl;
    }
};

int main() {
    ClapTrap c("Clappy");
    ScavTrap s("Scavvy");

    c.attack("ennemi");   // Version ClapTrap
    s.attack("ennemi");   // Version ScavTrap (redéfinie)
    s.guardGate();        // Propre à ScavTrap
    return 0;
}
```

---

### Notion 6 : Héritage multiple

**Pourquoi ?** C++ permet à une classe d'hériter de **plusieurs classes mères** simultanément. Cela permet de combiner des comportements venant de sources différentes.

**Exemple :**
```cpp
class FragTrap : public ClapTrap {
public:
    FragTrap(std::string nom) : ClapTrap(nom) {
        _pv      = 100;
        _energie = 100;
        _degats  = 30;
    }
    void highFivesGuys() {
        std::cout << _nom << " demande un high five !" << std::endl;
    }
};

// DiamondTrap hérite de ScavTrap ET de FragTrap
class DiamondTrap : public ScavTrap, public FragTrap {
public:
    DiamondTrap(std::string nom)
        : ScavTrap(nom), FragTrap(nom), _nom(nom) {
        _pv      = 100;
        _energie = 50;
        _degats  = 30;
    }

    void whoAmI() {
        std::cout << "Je suis DiamondTrap " << _nom << std::endl;
    }

    // Précise quelle version de attack() utiliser
    void attack(const std::string& cible) {
        ScavTrap::attack(cible);   // Utilise celle de ScavTrap
    }

private:
    std::string _nom;
};

int main() {
    DiamondTrap d("Diamond");
    d.attack("ennemi");    // Version ScavTrap
    d.guardGate();         // Hérité de ScavTrap
    d.highFivesGuys();     // Hérité de FragTrap
    d.whoAmI();
    return 0;
}
```

---

### Notion 7 : Le problème du diamant

**Pourquoi ?** Quand deux classes mères héritent toutes les deux d'une même grand-mère, et qu'une classe fille hérite des deux mères, il y a **ambiguïté** : la grand-mère est instanciée deux fois, et le compilateur ne sait pas laquelle utiliser.

**Schéma du problème :**
```
      ClapTrap          ← Grand-mère (instanciée 2 fois !)
       /      \
  ScavTrap  FragTrap    ← Chacune a SA propre copie de ClapTrap
       \      /
      DiamondTrap       ← Hérite des deux → ambiguïté
```

**Conséquence :**
```cpp
DiamondTrap d("test");
d.getName();   // ❌ Ambigu : getName() vient de ClapTrap,
               //    mais laquelle ? Celle de ScavTrap ou de FragTrap ?
```

**Solution 1 — Désambiguïsation explicite :**
```cpp
void DiamondTrap::whoAmI() {
    std::cout << "Nom DiamondTrap : " << _nom << std::endl;
    std::cout << "Nom ClapTrap    : " << ClapTrap::getName() << std::endl;
    //                                   ^^^^^^^^^^
    //                         On précise explicitement quelle version
}
```

**Solution 2 — Héritage virtuel :**
```cpp
// On ajoute "virtual" dans les classes intermédiaires
class ScavTrap : virtual public ClapTrap { /* ... */ };
class FragTrap : virtual public ClapTrap { /* ... */ };

// Maintenant DiamondTrap ne contient qu'UNE seule instance de ClapTrap
class DiamondTrap : public ScavTrap, public FragTrap {
public:
    // Avec l'héritage virtuel, c'est DiamondTrap qui doit appeler
    // directement le constructeur de ClapTrap
    DiamondTrap(std::string nom)
        : ClapTrap(nom + "_clap_name"),   // ← Obligatoire avec virtual
          ScavTrap(nom),
          FragTrap(nom),
          _nom(nom) {}
private:
    std::string _nom;
};
```

**Schéma après héritage virtuel :**
```
      ClapTrap          ← Une seule instance partagée
       /      \
  ScavTrap  FragTrap    ← Les deux "pointent" vers la même ClapTrap
       \      /
      DiamondTrap       ← Plus d'ambiguïté
```

---

### Notion 8 : Les flags de compilation `-Wshadow` et `-Wno-shadow`

**Pourquoi ?** Quand une classe fille déclare un attribut avec le **même nom** qu'un attribut de la classe mère, l'attribut de la fille **masque** celui de la mère. C'est le **shadowing** — source potentielle de bugs difficiles à détecter.

```
-Wshadow    → active un avertissement si une variable en masque une autre de portée supérieure
-Wno-shadow → désactive ce warning
```

**Exemple de shadowing :**
```cpp
class ClapTrap {
protected:
    std::string _name;   // Attribut dans la mère
};

class DiamondTrap : public ScavTrap, public FragTrap {
private:
    std::string _name;   // ⚠️ Même nom ! Masque ClapTrap::_name
                         // Avec -Wshadow, le compilateur avertit
};
```

Dans l'exercice DiamondTrap, ce shadowing est **intentionnel** : `DiamondTrap` a son propre `_name`, différent du `_name` hérité de `ClapTrap` (qui reçoit le nom suffixé `"_clap_name"`).

```cpp
void DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap name : " << _name             << std::endl;
    std::cout << "ClapTrap name    : " << ClapTrap::_name   << std::endl;
    // Les deux _name sont différents et coexistent
}
```

---

## 🔑 Notions clés

- Héritage : classe mère / classe fille, relation "est un"
- Syntaxe : `class Fille : public Mere {}`
- Trois types : `public` (le plus courant), `protected`, `private`
- `protected` : accessible dans la classe et ses filles, pas depuis l'extérieur
- Ordre : construction Parent → Enfant, destruction Enfant → Parent
- Appel explicite du constructeur parent : `: ClasseMere(params)` dans la liste d'initialisation
- Redéfinition de méthode (override) dans la classe fille
- Désambiguïsation explicite : `ClasseMere::methode()`
- Héritage multiple : `class Fille : public Mere1, public Mere2 {}`
- Problème du diamant : double instanciation de la grand-mère
- Héritage virtuel (`virtual public`) : résout le problème du diamant
- Avec héritage virtuel, c'est la classe la plus dérivée qui appelle le constructeur de la grand-mère
- Shadowing : masquage d'un attribut hérité par un attribut de même nom
- `-Wshadow` / `-Wno-shadow` : flags de compilation pour détecter/ignorer le shadowing
