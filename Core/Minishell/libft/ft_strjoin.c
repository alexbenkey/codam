/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbax <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/11 10:56:59 by jbax          #+#    #+#                 */
/*   Updated: 2022/02/24 13:52:16 by jbax          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		n;
	int		count;

	count = 0;
	n = ft_strlen(s1) + ft_strlen(s2) + 1;
	dest = malloc(n * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (*s1 != '\0')
	{
		dest[count] = *s1;
		count++;
		s1++;
	}
	while (*s2 != '\0')
	{
		dest[count] = *s2;
		count++;
		s2++;
	}
	dest[count] = '\0';
	return (dest);
}
