/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jordan <jordan@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/09 14:57:42 by jordan        #+#    #+#                 */
/*   Updated: 2021/12/01 16:30:09 by jbax          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	count;

	count = 0;
	while (count < n && (*(unsigned char *)s1) == (*(unsigned char *)s2))
	{
		s1++;
		s2++;
		count++;
	}
	if (count >= n)
		return (0);
	return ((*(unsigned char *)s1) - (*(unsigned char *)s2));
}
