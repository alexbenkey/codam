/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils_bonus.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/08 21:24:51 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/03/08 22:05:11 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strchr(const char *s, int c)
{
	char	*btemp;
	int		i;
	int		len;

	if (!s)
		return (-2);
	btemp = (char *)s;
	i = 0;
	while (s[i] != 0)
		i++;
	len = i;
	i = 0;
	while (i <= len)
	{
		if (s[i] == (unsigned char)c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*joined;

	if (!s1 || !s2)
		return (ft_strdup(s2));
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	joined = malloc((i + j + 1) * sizeof(char));
	if (joined == 0)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		joined[i + j] = s2[j];
		j++;
	}
	joined[i + j] = '\0';
	return (joined);
}

int	ft_strlen(const char *string)
{
	int	index;

	index = 0;
	if (!string[index])
		return (0);
	while (string[index] != 0)
		index++;
	return (index);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*newstr;
	size_t			strlen;

	i = 0;
	if (s == 0)
		return (NULL);
	strlen = ft_strlen(s);
	if (start > strlen)
		return (ft_strdup(""));
	if (len > strlen - start)
		return (ft_strdup(s + start));
	newstr = (char *)malloc((len + 1) * sizeof(char));
	if (newstr == 0)
		return (NULL);
	while (i < len)
	{
		newstr[i] = s[start + i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*newstr;

	i = 0;
	while (s[i])
		i++;
	newstr = malloc((i + 1) * sizeof(char));
	if (newstr == 0)
		return (NULL);
	i = 0;
	while (s[i])
	{
		newstr[i] = s[i];
		i++;
	}
	newstr[i] = '\0';
	return ((char *)newstr);
}
