#ifndef FIXED_HPP
#define FIXED_HPP

#include <algorithm>
#include <string>
#include <cctype>

#include <iostream>
#include <fstream>

#include <cmath>

class Fixed 
{
    private:
        int                 _fixedPointValue;
        static const int    _fractionalBits = 8;

    public:
        Fixed();
        Fixed(const Fixed &src);
        Fixed& operator=(const Fixed &src);
	    Fixed(const int intValue);
        Fixed(const float floatValue);
	    ~Fixed();

        int toInt(void) const;
        float toFloat(void) const;

        int getRawBits(void) const;
        void setRawBits(int const raw);

        // 6 comparison operators
        bool operator>(const Fixed& obj) const;
        bool operator<(const Fixed& obj) const;
        bool operator<=(const Fixed& obj) const;
        bool operator>=(const Fixed& obj) const;
        bool operator==(const Fixed& obj) const;
        bool operator!=(const Fixed& obj) const;

        // 4 arithmetic operators
        Fixed& operator+(const Fixed& obj);
        Fixed& operator-(const Fixed& obj);
        Fixed& operator*(const Fixed& obj);
        Fixed& operator/(const Fixed& obj);

        // 4 operators increment/decrement (pre-increment and post-increment, pre-decrement and post-decrement)
        Fixed& operator++();
        Fixed& operator--();
        Fixed& operator++(int);
        Fixed& operator--(int);

        // overloaded functions

        /*
        A static member function min that takes two references to fixed-point numbers as
        parameters, and returns a reference to the smallest one.
        • A static member function min that takes two references to constant fixed-point
        numbers as parameters, and returns a reference to the smallest one.
        • A static member function max that takes two references to fixed-point numbers as
        parameters, and returns a reference to the greatest one.
        • A static member function max that takes two references to constant fixed-point
        numbers as parameters, and returns a reference to the greatest one.
        */

};

#endif