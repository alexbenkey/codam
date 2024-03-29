#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
    public:
        ClapTrap(void);
        ClapTrap(std::string const name);
        ClapTrap(ClapTrap const &rhs);
        ClapTrap(std::string const name, ClapTrap const &rhs);
        ~ClapTrap(void);
        ClapTrap &          operator=(ClapTrap const &rhs);

        std::string     &get_name(void);
        void            set_name(std::string const &name);
        int             &get_hp(void);
        void            set_hp(int hp);
        int             &get_ep(void);
        void            set_ep(int ep);
        int             &get_ad(void);
        void            set_ad(int const ad);

        virtual void attack(const std::string &target);
        virtual void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
    
    protected:

        std::string _name;
        int         _hitpoints;
        int         _energypoints;
        int         _attackdamage;

};

#endif