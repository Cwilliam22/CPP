#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <cctype>
#include <iostream>
#include <exception>
#include <limits>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <stdint.h>

struct Data
{
    int         i;
    float       f;
    double      d;
    char        c;
};

class Serializer
{
	private:
        Serializer();
        Serializer(const Serializer& other);
        Serializer& operator=(const Serializer& other);
        ~Serializer();

	public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif