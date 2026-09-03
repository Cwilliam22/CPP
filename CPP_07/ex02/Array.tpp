#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(new T[0]), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) {
    for (size_t i = 0; i < n; i++)
        this->_array[i] = T();
}

template <typename T>
Array<T>::Array(const Array &other) : _array(new T[other._size]), _size(other._size) {
    for (size_t i = 0; i < other._size; i++)
        this->_array[i] = other._array[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other) {
    if (this != &other)
    {
        delete[] this->_array;
        this->_array = new T[other._size];
        this->_size = other._size;
        for (size_t i = 0; i < other._size; i++)
            this->_array[i] = other._array[i];
    }
    return (*this);
}

template <typename T>
Array<T>::~Array() {
    delete[] this->_array;
}

template <typename T>
T &Array<T>::operator[](unsigned int index) {
    if (index >= this->_size)
        throw OutOfBoundsException();
    return (this->_array[index]);
}

template <typename T>
size_t Array<T>::size() const {
    return (this->_size);
}
