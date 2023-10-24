#include "Harl.hpp"

int main (int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "please provide an input parameter for the program" << std::endl;
		return (1);
	}
	
	Harl instance;
	std::string input = argv[1];
	for (std::string::size_type j = 0; j < input.length(); j++)
		input[j] = std::toupper(input[j]);

	instance.complain(input);
}