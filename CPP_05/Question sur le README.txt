════════════════════════════════════════════════════════════════
NOTION 1
════════════════════════════════════════════════════════════════

Q : Le contenu des infos sur l'erreur OK mais pourquoi la lettre e ?
    Est-elle obligatoire ?
────────────────────────────────────────────────────────────────
Le `e` dans `catch (const std::runtime_error& e)` est simplement
un NOM DE VARIABLE — exactement comme le paramètre d'une fonction.
Tu peux l'appeler comme tu veux :

    catch (const std::runtime_error& monErreur)  { ... }
    catch (const std::runtime_error& err)        { ... }
    catch (const std::runtime_error& e)          { ... }  ← convention

Ce n'est pas obligatoire. C'est juste une convention courte et
lisible : "e" pour "exception" ou "erreur".

Si tu n'as pas besoin d'utiliser les infos de l'erreur dans le bloc
catch, tu peux même omettre le nom complètement :

    catch (const std::runtime_error&) {
        std::cerr << "Une erreur est survenue." << std::endl;
        // On n'utilise pas l'objet exception, donc pas besoin de nom
    }

════════════════════════════════════════════════════════════════

Q : Qu'est-ce que la fonction what() ?
    Pourquoi est-elle associée avec e ?
────────────────────────────────────────────────────────────────
`what()` est une MÉTHODE définie dans la classe `std::exception`
(et dans toutes ses classes dérivées). Elle retourne un `const char*`
(une chaîne de caractères C) qui décrit l'erreur.

Elle est associée à `e` parce que `e` EST l'objet exception qui a
été lancé par `throw`. Cet objet contient le message d'erreur, et
`what()` est le moyen d'y accéder :

    throw std::runtime_error("Division par zéro !");
    //    ↑ crée un objet avec le message "Division par zéro !"

    catch (const std::runtime_error& e) {
        e.what()  // → retourne "Division par zéro !"
    //  ↑
    //  e est l'objet lancé, .what() lit son message
    }

Analogie : imagine un courrier d'erreur qu'on envoie (throw).
`e` est le courrier reçu. `e.what()` c'est lire le contenu du
courrier.

════════════════════════════════════════════════════════════════

Q : Dans les exemples tu utilises std::runtime_error().
    C'est quoi ? Ça sert à quoi ?
────────────────────────────────────────────────────────────────
`std::runtime_error` est une CLASSE D'EXCEPTION STANDARD fournie
par C++ (dans <stdexcept>). Elle hérite de `std::exception`, donc
elle dispose de `what()`.

Elle sert à signaler des erreurs qui surviennent PENDANT L'EXÉCUTION,
c'est-à-dire des erreurs qu'on ne peut pas détecter à la compilation :
division par zéro, fichier introuvable, réseau coupé, etc.

Tu la crées en lui passant un message d'erreur :

    std::runtime_error("Division par zéro !")

La hiérarchie standard (rappel du README) :

    std::exception
        ├── std::logic_error      ← erreurs de logique du programmeur
        │       ├── std::invalid_argument
        │       └── std::out_of_range
        └── std::runtime_error    ← erreurs d'exécution imprévisibles
                ├── std::overflow_error
                └── std::underflow_error

Dans les exemples du README, `std::runtime_error` est utilisé pour
illustrer le mécanisme sans créer une classe personnalisée. En pratique,
pour tes propres erreurs, tu créeras tes propres classes (Notion 4).


════════════════════════════════════════════════════════════════
NOTION 2
════════════════════════════════════════════════════════════════

Q : throw peut lancer vraiment n'importe quoi ?
    Y a-t-il des limites ?
────────────────────────────────────────────────────────────────
Techniquement oui — le compilateur C++ autorise de lancer n'importe
quel type copiable. Mais EN PRATIQUE, il y a des règles importantes :

⚠️  NE PAS faire :
    throw 42;                       // Lance un int → impossible à
    throw std::string("erreur");    // attraper avec std::exception&

✅  TOUJOURS faire :
    throw MonException();           // Une classe héritant de std::exception

Les vraies LIMITES :

1. Le type doit être copiable (le compilateur peut avoir besoin
   d'en faire une copie).

2. Lancer depuis un DESTRUCTEUR est interdit. Si une exception est
   déjà en cours de propagation et qu'un destructeur en lance une
   autre, C++ appelle std::terminate() et le programme s'arrête.

3. Une fonction marquée `noexcept` ne peut pas lancer d'exception.
   Si elle le fait quand même, c'est std::terminate() directement.

4. `catch(...)` n'attrape PAS les exceptions système (segfault,
   signaux OS) — voir plus bas.

════════════════════════════════════════════════════════════════

Q : Dans le catch on fait figurer un "&" à la fin du type.
    Pourquoi ? Qu'est-ce qu'il amène comme précisions supplémentaires ?
────────────────────────────────────────────────────────────────
Le `&` signifie "attraper PAR RÉFÉRENCE" (et non par copie/valeur).
C'est crucial pour DEUX raisons :

── Raison 1 : le POLYMORPHISME (expliqué en Notion 3) ──────────

Sans `&` (par valeur), si tu lances un `GradeTooHighException` mais
que tu attrapes `std::exception`, l'objet est "découpé" (sliced) :
tu perds la partie spécifique de l'objet. `what()` ne retourne plus
le bon message.

    // ❌ Sans & → object slicing : `e` perd ses infos spécifiques
    catch (std::exception e) { e.what(); }

    // ✅ Avec & → polymorphisme : `e` pointe vers l'objet réel
    catch (const std::exception& e) { e.what(); }

── Raison 2 : la PERFORMANCE ───────────────────────────────────

Sans `&`, C++ doit faire une COPIE de l'objet exception. Avec `&`,
on accède directement à l'objet lancé, sans copie inutile.

Le `const` en plus garantit qu'on ne modifie pas l'exception dans
le bloc catch (bonne pratique).

════════════════════════════════════════════════════════════════

Q : catch (const std::exception& e) — Qu'est-ce que tu entends
    par "exceptions dérivées" ?
────────────────────────────────────────────────────────────────
"Dérivée" = une classe qui HÉRITE d'une autre (héritage en POO).

`std::runtime_error` est une classe DÉRIVÉE de `std::exception` :
elle hérite d'elle. Ça veut dire qu'un objet `runtime_error` EST
AUSSI un `std::exception`.

En C++, un `catch (const std::exception& e)` attrape TOUT objet
dont la classe est `std::exception` OU dont la classe EN HÉRITE :

    catch (const std::exception& e)
    //         ↑ Attrape :
    //         • std::exception elle-même
    //         • std::runtime_error (hérite de std::exception)
    //         • std::logic_error   (hérite de std::exception)
    //         • std::out_of_range  (hérite de logic_error → hérite de std::exception)
    //         • TonException       (si elle hérite de std::exception)

C'est pourquoi on dit que c'est un catch "générique" : il couvre
toute la famille d'exceptions standard.

════════════════════════════════════════════════════════════════

Q : Tu dis que catch (...) attrape tout.
    Est-ce qu'il existe des exceptions à cette règle ?
────────────────────────────────────────────────────────────────
Oui. `catch(...)` attrape toutes les EXCEPTIONS C++. Mais il
n'attrape PAS :

1. Les SIGNAUX SYSTÈME (SIGSEGV pour segfault, SIGILL, etc.)
   Ce sont des événements du système d'exploitation, pas des
   exceptions C++. Un accès mémoire invalide ne se "catch" pas.

2. `std::terminate()` lui-même — quand le programme s'arrête via
   terminate(), aucun catch ne peut l'intercepter.

En pratique, dans un code C++ normal, `catch(...)` attrape bien
tout ce que tu peux lancer avec `throw`.

Inconvénient de `catch(...)` : tu ne sais PAS quel type a été
lancé, et tu n'as AUCUNE information sur l'erreur (pas de .what()).
C'est le filet de sécurité de dernier recours, pas la solution
normale.


════════════════════════════════════════════════════════════════
NOTION 3
════════════════════════════════════════════════════════════════

Q : Polymorphisme — Je ne comprends pas cette notion ni l'enjeu.
────────────────────────────────────────────────────────────────

── C'est quoi le polymorphisme ? ───────────────────────────────

"Polymorphisme" vient du grec : poly = plusieurs, morphe = formes.
En POO, ça veut dire qu'un objet peut être traité selon PLUSIEURS
TYPES en même temps.

Exemple concret sans exception d'abord :

    class Animal {
    public:
        virtual void parler() { std::cout << "..." << std::endl; }
    };

    class Chien : public Animal {
    public:
        void parler() { std::cout << "Ouaf !" << std::endl; }
    };

    class Chat : public Animal {
    public:
        void parler() { std::cout << "Miaou !" << std::endl; }
    };

    Animal* a = new Chien();
    a->parler();  // Affiche "Ouaf !" — pas "..."
    //  ↑
    //  `a` est de type Animal*, mais l'objet RÉEL est un Chien.
    //  Grâce au mot-clé `virtual`, C++ appelle la méthode du VRAI
    //  type de l'objet (Chien), pas celle du type de la variable (Animal).

C'est ça le polymorphisme : même si on manipule une référence
de type "parent", on obtient le comportement du type "enfant".

── Pourquoi virtual ? ──────────────────────────────────────────

Sans `virtual`, C++ décide quelle méthode appeler au MOMENT DE LA
COMPILATION, selon le type de la VARIABLE. Avec `virtual`, il décide
au MOMENT DE L'EXÉCUTION, selon le type RÉEL de l'OBJET.

    // Sans virtual :
    Animal* a = new Chien();
    a->parler();  // → "..."  ← utilise Animal::parler, mauvais !

    // Avec virtual :
    Animal* a = new Chien();
    a->parler();  // → "Ouaf !" ← utilise Chien::parler, correct !

── Application aux exceptions ──────────────────────────────────

`what()` est déclarée `virtual` dans `std::exception`. C'est ce
qui permet le polymorphisme des exceptions.

    class ErreurBanque : public std::exception {
        const char* what() const throw() { return "Erreur banque"; }
    };

    class SoldeInsuffisant : public ErreurBanque {
        const char* what() const throw() { return "Solde insuffisant !"; }
    };

Quand on throw un `SoldeInsuffisant` et qu'on le catch comme
`ErreurBanque&` :

    try {
        throw SoldeInsuffisant();       // L'objet RÉEL est SoldeInsuffisant
    }
    catch (const ErreurBanque& e) {    // On le reçoit comme ErreurBanque
        std::cout << e.what();         // → "Solde insuffisant !" ← what() de SoldeInsuffisant
    }                                  //   pas "Erreur banque"

`e` est de type `ErreurBanque&` (le type de la variable), mais
l'objet réel est un `SoldeInsuffisant`. Grâce à `virtual`, `e.what()`
appelle la méthode de `SoldeInsuffisant`, pas celle de `ErreurBanque`.

── L'enjeu concret ─────────────────────────────────────────────

Sans polymorphisme, tu devrais écrire un catch pour CHAQUE type
d'exception. Avec, tu peux écrire un seul catch générique et
bénéficier quand même du bon message pour chaque exception :

    // ❌ Sans polymorphisme : 10 catches si 10 types d'erreur
    catch (const SoldeInsuffisant& e)   { cerr << e.what(); }
    catch (const CompteBloqueException& e) { cerr << e.what(); }
    catch (const LimiteAtteinte& e)     { cerr << e.what(); }
    // ...

    // ✅ Avec polymorphisme : 1 seul catch, what() reste correct
    catch (const ErreurBanque& e) {
        cerr << e.what();  // Appelle le bon what() selon le type réel
    }

── Résumé en une phrase ────────────────────────────────────────

Le polymorphisme permet à une variable de type "parent" de se
comporter comme le type "enfant" de l'objet qu'elle contient,
grâce au mot-clé `virtual` qui résout les appels de méthodes
au moment de l'exécution et non à la compilation.




Aucun catch sur exception lancé amène à un crash -> une erreur
Try et catch dans le bloc main et trow dans le constructeur -> pourquoi ? Autres méthodes ?
Syntaxe sur la façon de récupérer les exceptions
Revoir l'encapsulation au niveau de la class
Revoir l'encapsulation des exceptions