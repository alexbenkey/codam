#include "Harl.hpp"

int main (void)
{
	Harl instance;

	instance.complain("debug");
	instance.complain("info");
	instance.complain("warning");
	instance.complain("error");
	instance.complain("trap");

}