#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <deque>


template <class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
    private:

    public:
        MutantStack();
        MutantStack(const MutantStack& src);
        MutantStack& operator=(const MutantStack& src);
        ~MutantStack();

        typedef typename Container::iterator iterator;
        iterator begin();
        iterator end();

};

#include "MutantStack.tpp"

#endif