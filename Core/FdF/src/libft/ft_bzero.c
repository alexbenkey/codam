/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 18:51:50 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/10/24 18:51:51 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(char	*mystring, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		mystring[i] = 0;
		i++;
	}
}
