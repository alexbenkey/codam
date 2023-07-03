/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbax <jbax@student.42.fr>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/05 12:06:43 by jbax          #+#    #+#                 */
/*   Updated: 2021/12/03 15:31:07 by jbax          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	count;

	count = 0;
	while (count < len)
	{
		((char *)b)[count] = c;
		count++;
	}
	return (b);
}
