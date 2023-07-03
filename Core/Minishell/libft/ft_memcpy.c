/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbax <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 09:43:04 by jbax          #+#    #+#                 */
/*   Updated: 2021/12/01 12:13:03 by jbax          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *stc, size_t n)
{
	unsigned int	count;

	count = 0;
	if (!dest && !stc)
	{
		return (dest);
	}
	while (count < n)
	{
		((char *)dest)[count] = ((char *)stc)[count];
		count++;
	}
	return (dest);
}
