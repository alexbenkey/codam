#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap bob("bob");
	ClapTrap james("james");
	ClapTrap tim = ClapTrap("tim");

	bob.attack(james.get_name());
	james.takeDamage(3);
	bob.takeDamage(3);
	bob.takeDamage(3);
	bob.takeDamage(3);
	bob.takeDamage(3);
	bob.takeDamage(3);
	bob.takeDamage(3);
	bob.takeDamage(3);
	bob.takeDamage(3);
	bob.takeDamage(3);
	bob.takeDamage(3);
	bob.beRepaired(2);
	bob.attack(james.get_name());
	james.takeDamage(0);
	tim.attack(bob.get_name());
	bob.takeDamage(0);
	bob.beRepaired(5);
	
}