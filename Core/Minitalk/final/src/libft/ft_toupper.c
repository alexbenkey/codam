/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 18:55:18 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/10/24 18:55:19 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int input)
{	
	if (input >= 97 && input <= 122)
		return (input - 32);
	else
		return (input);
}
