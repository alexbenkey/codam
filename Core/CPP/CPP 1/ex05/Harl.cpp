#include "Harl.hpp"

Harl::Harl (void)
{
	std::cout << "Harl has been created" << std::endl;
}

Harl::~Harl (void)
{
	std::cout << "Harl has been destroyed" << std::endl;
}

void Harl::debug (void) 
{
	std::cout << "I am a huge fan of complaining, it is one of my favourite things to do." << std::endl;
}

void Harl::info 		(void) 
{
	std::cout << "If you do not let me complain, I might get very upset and start complaining about stuff. Which will ultimately reduce my need to complain." << std:: endl;
}

void Harl::warning 	(void) 
{
	std::cout << "Look, you should really stop complaining about my love of complaining, it is severely counterproductive, I will just complain more! " << std::endl;
}

void Harl::error		(void) 
{
	std::cout << "Thats it, you have done it, no more complaining ,we will now fight to the DEATH!"  << std::endl;
}

void Harl::complain 	(std::string level)
{
	// void  (Harl::*memfct[4]) (void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	memfct array[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	std::size_t stop = 0;
	std::string	msg[4] = {"debug", "info", "warning", "error"};

	for (int i = 0; i < 4; i++)
	{
		if (msg[i] == level)
		{
			stop++;
			(this->*(array[i]))();
		}
		if (i == 3 && !stop)
		{
			std::cout << "Harl would like to complain about the fact that you did not input a correct attribute!" << std::endl;
		}
	}
}