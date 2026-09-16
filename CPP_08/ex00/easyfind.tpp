// #include "easyfind.hpp" 
// le fichier .tpp est inclu depuis le .hpp est non l'inverse

template <typename T>
typename T::iterator easyfind(T &values, int wanted) {
    for (typename T::iterator it = values.begin(); it != values.end(); ++it)
    {
        if (*it == wanted)
            return (it);
    }
    throw NotFoundException();
}
