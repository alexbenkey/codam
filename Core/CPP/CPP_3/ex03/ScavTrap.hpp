#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
    public:

        ScavTrap(std::string const name);
        ~ScavTrap(void);

        void    attack(const std::string &target);
        void    guardGate(void);
        int     get_defaulthp(void) const;
		int     get_defaultep(void) const;
		int     get_defaultad(void) const;

    private:
        const int         _defaultHP = 100;
        const int         _defaultEP = 50;
        const int         _defaultAD = 20;

    protected:

        ScavTrap(void);
};

#endif