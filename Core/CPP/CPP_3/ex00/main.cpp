#include "Claptrap.hpp"

int main(void)
{
	Claptrap bob("bob");
	Claptrap james("james");
	Claptrap tim = Claptrap("tim");

	bob.attack(james.get_name());
	james.takeDamage(3);
	bob.beRepaired(2);
	bob.takeDamage(3);
	bob.attack(james.get_name());
	james.takeDamage(0);
}