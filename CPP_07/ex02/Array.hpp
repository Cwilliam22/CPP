#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <exception>

template <typename T>

class Array
{
    private:
        T *_array;
        size_t _size;

    public:
        Array();
        Array(unsigned int n);
        Array(const Array &other);
        Array &operator=(const Array &other);
        ~Array();

        T &operator[](unsigned int index);

        size_t size() const;

        class OutOfBoundsException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return "Index out of bounds";
                }
        };

};

#include "Array.tpp"

#endif