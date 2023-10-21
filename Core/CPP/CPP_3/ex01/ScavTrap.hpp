#ifndef ScavTrap_HPP
# define SCATRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
    public:

        ScavTrap(void);
        ScavTrap(ScavTrap const &rhs);
        ScavTrap(std::string const name);
        ScavTrap(std::string const name, ScavTrap const &rhs);
        ScavTrap &operator=(ScavTrap const &rhs);
        ~ScavTrap(void);

        void attack(const std::string &target);
        void guardGate(void);

    private:

        std::string     _name;
        int             _hp;
        int             _ep;
        int             _ad;
};

#endif