#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"

class DiamondTrap : public ClapTrap
{
	private:
        std::string         _name;

	public:
		DiamondTrap(const std::string name);
		~DiamondTrap();

        void whoAmI();

};

#endif