#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <algorithm>
#include <string>
#include <cctype>
#include <iostream>
#include <fstream>
#include <cmath>

class WrongAnimal
{
    protected:
        std::string _type;

	public:
		WrongAnimal();
        WrongAnimal(const WrongAnimal& other);
	    WrongAnimal& operator=(const WrongAnimal& other);
		virtual ~WrongAnimal();

        virtual void makeSound() const;
        std::string getType() const;

};

#endif