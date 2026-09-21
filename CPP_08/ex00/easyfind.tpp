// #include "easyfind.hpp" 
// le fichier .tpp est inclu depuis le .hpp est non l'inverse

template <typename T>
typename T::iterator easyfind(T &values, int wanted) {
    typename T::iterator it = std::find(values.begin(), values.end(), wanted);
    if (it == values.end())
        throw NotFoundException();
    return (it);
}
