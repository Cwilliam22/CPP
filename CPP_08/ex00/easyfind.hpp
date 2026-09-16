#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>

template <typename T> // template pour variable generique
typename T::iterator // type de retour de la fonction easyfind
easyfind(T &values, int wanted); // fonction

class NotFoundException : public std::exception
{
	public:
		const char* what() const throw() {
			return ("Not find!");
        }
};

#include "easyfind.tpp"

#endif