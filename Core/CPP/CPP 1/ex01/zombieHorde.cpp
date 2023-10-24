/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:07:08 by avon-ben          #+#    #+#             */
/*   Updated: 2023/10/11 17:05:40 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string str)
{
	Zombie *array = new Zombie[N];
	
	for (int i = 0; i < N; i++)
		array[i].set_name(str + std::to_string(i));
	return (array); 
}