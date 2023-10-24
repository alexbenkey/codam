/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:07:12 by avon-ben          #+#    #+#             */
/*   Updated: 2023/10/11 17:08:18 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "a zombie has been constructed" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "a zombie has been destroyed" << std::endl;
}

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
	std::cout << get_name() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
