/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbax <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/08 13:06:25 by jbax          #+#    #+#                 */
/*   Updated: 2022/02/25 16:55:20 by jbax          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checkmalloc(void **dest, int count)
{
	int	i;

	i = 0;
	if (dest[count] == NULL)
	{
		if (count > 0)
		{
			while (i < count)
			{
				free (dest[i]);
				i++;
			}
		}
		free (dest);
		return (0);
	}
	else
		return (1);
}

static int	*ft_counting(char const *s, char c, int *len, int i)
{
	int	count;
	int	temp;

	temp = 0;
	count = 0;
	while (s[count] != '\0')
	{
		if (s[count] == c)
		{
			if (count > 0 && s[count - 1] != c)
			{
				len[i] = (count - temp) + 1;
				i++;
				temp = count;
			}
			temp++;
		}
		count++;
	}
	if (count > 0 && s[count - 1] != c)
		len[i] = (count - temp) + 1;
	if (count > 0 && s[count - 1] != c)
		i++;
	len[i] = 1;
	return (len);
}

static int	ft_coreloop(char const *s, char c, char **dest, int count)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[count] != '\0')
	{
		if (s[count] != c)
		{
			while (s[count] != c && s[count] != '\0')
			{
				dest[i][j] = s[count];
				j++;
				count++;
			}
			dest[i][j] = '\0';
			j = 0;
			i++;
		}
		else
			count++;
	}
	dest[i] = NULL;
	return (0);
}

static char	**ft_splitter(int limiter, int *len, char const *s, char c)
{
	char	**dest;
	int		i;

	i = 0;
	dest = (char **)malloc((limiter + 1) * sizeof(char *));
	if (dest == NULL)
		return (NULL);
	while (i < limiter)
	{	
		dest[i] = (char *)malloc(len[i] * sizeof(char));
		if (ft_checkmalloc(((void **)dest), i) == 0)
			return (NULL);
		i++;
	}
	ft_coreloop(s, c, dest, 0);
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	int		limiter;
	char	**dest;
	int		*len;

	limiter = 0;
	count = 0;
	while (s[count] != '\0')
	{
		if (count > 0 && s[count] == c && s[count - 1] != c)
			limiter++;
		count++;
	}
	if (count >= 1 && s[count - 1] != c)
		limiter++;
	len = malloc((limiter + 1) * sizeof(int));
	if (len == NULL)
		return (NULL);
	len = ft_counting(s, c, len, 0);
	dest = ft_splitter(limiter, len, s, c);
	free (len);
	if (dest == NULL)
		return (NULL);
	return (dest);
}
