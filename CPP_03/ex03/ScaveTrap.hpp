#ifndef SCAVETRAP_HPP
#define SCAVETRAP_HPP

#include "ClapTrap.hpp"

class ScaveTrap : public ClapTrap
{
	private:

	public:
		ScaveTrap(const std::string name);
		~ScaveTrap();

        void guardGate();
};

#endif