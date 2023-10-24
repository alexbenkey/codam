/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:07:32 by avon-ben          #+#    #+#             */
/*   Updated: 2023/10/11 16:35:39 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <iomanip>

class Zombie {

public:
	Zombie(void);	
	~Zombie(void);
	void 		announce(void);
	std::string get_name(void) const;
	void		set_name(std::string);

private:
	std::string _name;
};

Zombie	*zombieHorde(int N, std::string name);

#endif