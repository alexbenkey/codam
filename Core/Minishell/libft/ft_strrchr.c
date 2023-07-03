/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbax <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/03 13:13:06 by jbax          #+#    #+#                 */
/*   Updated: 2021/12/10 16:20:54 by jbax          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	count;

	count = 0;
	while (*s != '\0')
	{
		if (*s == (char)c)
			count++;
		s++;
	}
	if (count <= 0 && *s != (char)c)
		return (NULL);
	if (count >= 1)
	{
		while (*s != (char)c)
			s--;
	}
	return ((char *)s);
}
