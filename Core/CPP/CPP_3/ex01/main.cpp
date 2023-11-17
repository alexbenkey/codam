#include "ClapTrap.hpp"
#include "ScavTrap.hpp"


int main (void)
{
    ScavTrap nina("Nina");
    ScavTrap anna("Anna");

    {
    ClapTrap bob("Bob");
    ClapTrap steve("Steve", bob);
    bob.attack("Steve");
    steve.takeDamage(0);
    steve.attack("Bob");
    bob.takeDamage(0);
    bob.beRepaired(1);
    steve.attack("Bob");

    nina.attack("Bob");
    bob.takeDamage(20);
    steve.takeDamage(10);
    bob.attack("Steve");
    bob.beRepaired(3);
    bob.takeDamage(2);
    anna.attack("Nina");
    nina.takeDamage(20);
    nina.guardGate();
    }

    anna.attack("Nina");
    nina.takeDamage(20);
    nina.attack("Anna");
    anna.takeDamage(20);
    anna.beRepaired(10);
    nina.attack("Anna");
    anna.takeDamage(20);
    anna.attack("Nina");
    nina.takeDamage(20);
    nina.attack("Anna");
    anna.takeDamage(20);
    anna.attack("Nina");
    nina.takeDamage(20);
    nina.attack("Anna");
    anna.takeDamage(20);
    anna.beRepaired(10);
    nina.attack("Anna");
    anna.takeDamage(20);
    anna.attack("Nina");
    nina.takeDamage(20);
    nina.attack("Anna");
    anna.takeDamage(20);
}