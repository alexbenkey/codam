/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jordan <jordan@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/13 11:15:38 by jordan        #+#    #+#                 */
/*   Updated: 2021/12/01 16:29:17 by jbax          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	count;

	count = 0;
	while (count < n && (*(unsigned char *)s1) == (*(unsigned char *)s2))
	{
		if ((*(unsigned char *)s1) == '\0')
			count = n;
		s1++;
		s2++;
		count++;
	}
	if (count >= n)
		return (0);
	return ((*(unsigned char *)s1) - (*(unsigned char *)s2));
}
