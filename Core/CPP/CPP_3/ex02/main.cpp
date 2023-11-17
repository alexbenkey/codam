#include "ScavTrap.hpp"
#include "FragTrap.hpp"


int main (void)
{
    ClapTrap bob("Bob");
    ClapTrap steve("Steve", bob);
    ScavTrap nina("Nina");
    ScavTrap anna("Anna");
    FragTrap red("red");
    FragTrap blue("blue");

    red.highFivesGuys();
    blue.highFivesGuys();
    red.attack(bob.get_name());
    bob.takeDamage(red.get_ad());

    bob.attack("steve");
    steve.takeDamage(bob.get_ad());
    steve.attack(bob.get_name());
    bob.takeDamage(0);
    bob.beRepaired(1);
    steve.attack("bob");

    nina.attack("bob");
    bob.takeDamage(20);
    steve.takeDamage(10);
    bob.attack("steve");
    bob.beRepaired(3);
    bob.takeDamage(2);
    anna.attack("nina");
    nina.takeDamage(20);
    nina.guardGate();

    anna.attack("nina");
    nina.takeDamage(5);
    nina.attack("anna");
    anna.takeDamage(20);
    anna.beRepaired(10);
    nina.attack("anna");
    anna.takeDamage(20);
    anna.attack("nina");
    nina.takeDamage(5);
    nina.attack("anna");
    anna.takeDamage(20);
    anna.attack("nina");
    nina.takeDamage(5);
    nina.attack("anna");
    anna.takeDamage(20);
    anna.beRepaired(10);
    nina.attack("anna");
    anna.takeDamage(20);
    anna.attack("nina");
    nina.takeDamage(5);
    nina.attack("anna");
    anna.takeDamage(20);
}