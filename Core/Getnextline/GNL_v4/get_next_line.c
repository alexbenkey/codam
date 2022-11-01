/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/08 21:24:49 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/03/11 19:47:23 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_clear(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = 0;
		return (1);
	}
	return (0);
}

int	read_from_buf(int fd, char **leftovers)
{
	char	*temp;
	char	read_str[BUFFER_SIZE + 1];
	int		r;

	while (ft_strchr(*leftovers, '\n') == -1)
	{	
		r = read(fd, read_str, BUFFER_SIZE);
		read_str[r] = '\0';
		temp = ft_strjoin(*leftovers, read_str);
		if (!ft_clear((void **)leftovers))
			return (0);
		*leftovers = temp;
		if (r < 1)
		{
			r = -1;
			break ;
		}
	}
	return (r);
}

void	*ft_calloc(size_t nelem, size_t elsize)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(elsize * nelem);
	if (str == 0)
		return (NULL);
	i = 0;
	while (i < (nelem * elsize))
	{
		str[i] = 0;
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*check_block(char *lo, int r)
{
	char	*rl;

	if (lo[0] == '\n')
		rl = ft_substr(lo, 0, 1);
	else if (r == -1)
		rl = ft_strdup(lo);
	else if (ft_strchr(lo, '\n') && ft_strchr(lo, '\n') != (ft_strlen(lo)))
		rl = ft_substr(lo, 0, (ft_strchr(lo, '\n') + 1));
	else
		rl = NULL;
	return (rl);
}

char	*get_next_line(int fd)
{
	static char	*lo = NULL;
	int			r;
	char		*rl;
	char		*tmp;

	if (BUFFER_SIZE < 1 || read(fd, NULL, 0) < 0)
		return (NULL);
	if (!lo)
		lo = ft_calloc(BUFFER_SIZE + 1, 1);
	r = read_from_buf(fd, &lo);
	if (!lo[0])
	{
		if (ft_clear((void **)&lo))
			return (NULL);
	}
	rl = check_block(lo, r);
	if (!rl)
		return (NULL);
	tmp = ft_substr(lo, ft_strlen(rl), (ft_strlen(lo) - (ft_strlen(rl))));
	ft_clear((void **)&lo);
	lo = tmp;
	return (rl);
}
