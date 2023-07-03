/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbax <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/26 13:55:52 by jbax          #+#    #+#                 */
/*   Updated: 2021/12/01 12:15:28 by jbax          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int	count;

	count = 0;
	if (!dest && !src)
		return (dest);
	if (dest <= src)
	{
		while (count < n)
		{
			((char *)dest)[count] = ((char *)src)[count];
			count++;
		}
	}
	else
	{
		count = n;
		while (count != 0)
		{
			((char *)dest)[count - 1] = ((char *)src)[count - 1];
			count--;
		}
	}
	return (((char *)dest));
}
