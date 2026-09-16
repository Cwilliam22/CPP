#include "MutantStack.hpp"

template <class T, class Container>
MutantStack<T, Container>::MutantStack() {}

template <class T, class Container>
MutantStack<T, Container>::MutantStack(const MutantStack& src) : std::stack<T, Container>(src) {}

template <class T, class Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(const MutantStack& src) {
    if (this != &src)
        std::stack<T, Container>::operator=(src);
    return (*this);
}

template <class T, class Container>
MutantStack<T, Container>::~MutantStack() {

}

template <class T, class Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin() {
    return (this->c.begin());
}

template <class T, class Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end() {
    return (this->c.end()); 
}