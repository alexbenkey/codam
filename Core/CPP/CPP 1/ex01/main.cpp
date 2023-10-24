/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:07:06 by avon-ben          #+#    #+#             */
/*   Updated: 2023/10/11 17:03:40 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main (void)
{
	int amount = 20;
	Zombie *horde = zombieHorde(amount, "james");
	for(int i = 0; i< amount; i++)
	{
		horde[i].announce();
	}
	delete [] horde;
	return (0);
}
