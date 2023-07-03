/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbax <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/26 17:44:15 by jbax          #+#    #+#                 */
/*   Updated: 2022/02/24 16:00:34 by jbax          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_counting(char const *s1, char const *set, int count)
{
	int	n;

	n = 0;
	while (set[n] != '\0')
	{
		if (set[n] == s1[count])
		{
			count++;
			n = 0;
		}
		else
			n++;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	int		n;
	int		count;
	int		i;

	i = ft_strlen(s1);
	n = 0;
	count = ft_counting(s1, set, 0);
	while (set[n] != '\0')
	{
		if (i > 0 && set[n] == s1[i - 1])
		{
			i--;
			n = 0;
		}
		else
			n++;
	}
	i = i - count;
	if (i < 0)
		i = 0;
	dest = ft_substr(s1, count, i);
	if (dest == NULL)
		return (NULL);
	return (dest);
}
