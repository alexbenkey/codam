#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class Claptrap{
	public:
		Claptrap(void);
		~Claptrap(void);
		Claptrap(std::string name);

		Claptrap &operator=(Claptrap const &rhs);

		void set_name(std::string);
		std::string &get_name(void);
		void attack(std::string &target);
		void takeDamage (unsigned int amount);
		void beRepaired(unsigned int amount);
		int	 Potential(void);

	private:
		std::string _name;
		int 		_hitpoints;
		int 		_energypoints;
		int 		_Attack_damage;
		int			_maxhp;
};

#endif