#include "Zombie.hpp"

std::string Zombie::get_name(void) const
{
	return (this->_name);
}

void Zombie::set_name(std::string str)
{
	this->_name = str;
}

void Zombie::announce(void)
{
	std::cout << get_name;
	std::cout << "BraiiiiiiinnnzzzZ..." << std::endl;
}

int main (void)
{

}
