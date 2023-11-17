#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap{
	public:
		ClapTrap(void);
		~ClapTrap(void);
		ClapTrap(ClapTrap const &rhs);
		ClapTrap(std::string name);

		ClapTrap &operator=(ClapTrap const &rhs);

		void set_name(std::string);
		std::string &get_name(void);
		void attack(std::string &target);
		void takeDamage (unsigned int amount);
		void beRepaired(unsigned int amount);
		int	 potential(void);

	private:
		std::string _name;
		int 		_hitpoints;
		int 		_energypoints;
		int 		_attack_damage;
		int			_maxhp;
};

#endif