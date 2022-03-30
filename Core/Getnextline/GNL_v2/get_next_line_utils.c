/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 20:04:13 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/03/02 00:34:55 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(char	*mystring, size_t len)
{
	size_t	i;

	i = 0;
	//printf("my string: %s", mystring);
	while (i < len)
	{
		mystring[i] = 0;
		i++;
	}
	mystring[i] = 0;
}

int	check_for_newline_in_string(char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == '\n')
		{
			if (i == (ft_strlen(string) - 1))
				return (-1);
			return (i + 1);
		}
		i++;
	}
	return (0);
}

int	count_nl(char *string)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (string[i])
	{
		if (string[i] == '\n')
			n++;
		i++;
	}
	return (n);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	*ft_calloc(size_t nelem, size_t elsize)
{
	char	*str;

	str = (char *)malloc(elsize * nelem);
	if (str == 0)
		return (NULL);
	ft_bzero(str, (elsize * nelem));
	return (str);
}

char	*ft_strjoin(char *destination, char *source)
{
	int		i;
	int		j;
	char	*joined;

	i = (ft_strlen(destination) + ft_strlen(source));
	joined = ft_calloc(i + 1, 1);
	if (joined == 0)
		return (NULL);
	i = 0;
	j = 0;
	while (destination[i])
	{
		joined[i] = destination[i];
		i++;
	}
	while (source[j])
	{
		joined[i + j] = source[j];
		j++;
	}
	joined[i + j] = '\0';
	//free(destination);
	return ((char *)joined);
}

int	ft_clear(void **ptr)
{
	if (*ptr)
	{
		ft_memset(*ptr, 0, ft_strlen(*ptr));
		free(*ptr);
		*ptr = 0;
		return (1);
	}
	return (0);
}

void	*ft_memset(char	*mystring, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		mystring[i] = c;
		i++;
	}
	return (mystring);
}
