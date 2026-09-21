#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>

template <typename T>
typename T::iterator easyfind(T &values, int wanted);

class NotFoundException : public std::exception
{
	public:
		const char* what() const throw() {
			return ("Not find!");
        }
};

#include "easyfind.tpp"

#endif