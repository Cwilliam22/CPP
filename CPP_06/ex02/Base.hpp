#ifndef BASE_HPP
#define BASE_HPP

#include <string>
#include <cctype>
#include <iostream>
#include <exception>
#include <limits>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <stdint.h>

class Base
{
	private:

	public:
        virtual ~Base();

};

class A : public Base {};
class B : public Base {};
class C : public Base {};


Base* generate(void);
void identify(Base* p);
void identify(Base& p);


#endif