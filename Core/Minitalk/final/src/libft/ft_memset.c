/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 18:53:31 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/10/24 18:53:32 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(char	*mystring, int c, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		mystring[i] = c;
		i++;
	}
	return (mystring);
}
