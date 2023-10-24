#include <iostream>
#include <iomanip>

int main (void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string &stringREF = str;
	std::string *stringPTR;

	stringPTR = &str;
	std::cout << &str << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;

	std::cout << str << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;

	return (0);
}