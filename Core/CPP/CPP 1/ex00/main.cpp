/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:07:06 by avon-ben          #+#    #+#             */
/*   Updated: 2023/10/03 13:07:07 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main (void)
{
	Zombie *instance = newZombie("james");
	//Zombie *instance1 = factory.newZombie("steve");

	randomChump("bob");
	delete instance;
	//system("leaks zombies");
	return (0);
}
