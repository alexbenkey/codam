/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin3.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbax <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/11 10:56:59 by jbax          #+#    #+#                 */
/*   Updated: 2023/02/27 19:15:53 by jbax          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	loop_content(char **dest, char const *s, int *i)
{
	while (*s != '\0')
	{
		dest[0][*i] = *s;
		*i += 1;
		s++;
	}
}

char	*ft_strjoin3(char const *s1, char const *s2, char const *s3)
{
	char	*dest;
	int		n;
	int		count;

	count = 0;
	n = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3) + 1;
	dest = malloc(n * sizeof(char));
	if (dest == NULL)
		return (NULL);
	loop_content(&dest, s1, &count);
	loop_content(&dest, s2, &count);
	loop_content(&dest, s3, &count);
	dest[count] = '\0';
	return (dest);
}
