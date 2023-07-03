/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jordan <jordan@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/09 15:04:33 by jordan        #+#    #+#                 */
/*   Updated: 2021/12/15 15:26:00 by jbax          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	count;

	count = 0;
	while (count < n)
	{
		if ((*(unsigned char *)s) == ((unsigned char)c))
			return (((unsigned char *)s));
		s++;
		count++;
	}
	return (NULL);
}
