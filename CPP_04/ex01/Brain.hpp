#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "Animal.hpp"

class Brain
{
    private:
        std::string _ideas[100];

	public:
		Brain();
        Brain(const Brain& other);
	    Brain& operator=(const Brain& other);
		virtual ~Brain();

        void setIdea(int index, const std::string& idea);
        std::string getIdea(int index) const;

};

#endif