#include "Harl.hpp"

Harl::Harl (void){
}

Harl::~Harl (void){
}

void Harl::debug (void) 
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I am a huge fan of complaining, it is one of my favourite things to do." << std::endl;
	std::cout << std::endl;
}

void Harl::info 		(void) 
{
	std::cout << "[INFO]" << std::endl;
	std::cout << "If you do not let me complain, I might get very upset and start complaining about stuff. Which will ultimately reduce my need to complain." << std:: endl;
	std::cout << std::endl;
}

void Harl::warning 	(void) 
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << "Look, you should really stop complaining about my love of complaining, it is severely counterproductive, I will just complain more! " << std::endl;
	std::cout << std::endl;

}

void Harl::error		(void) 
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << "Thats it, you have done it, no more complaining ,we will now fight to the DEATH!"  << std::endl;
	std::cout << std::endl;
}

void Harl::complain 	(std::string level)
{
	memfct array[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	int index = 5;
	std::string	msg[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (msg[i] == level)
			index = i;
	}

	switch (index)
	{
		case (0):
			for (int i = 0; i < 4; i++)
				(this->*(array[i]))();
			break;
		case (1):
			for (int i = 1; i < 4; i++)
				(this->*(array[i]))();
			break;
		case (2):
			for (int i = 2; i < 4; i++)
				(this->*(array[i]))();
			break;
		case (3):
			for (int i = 3; i < 4; i++)
				(this->*(array[i]))();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			std::cout << std::endl;
	}
}