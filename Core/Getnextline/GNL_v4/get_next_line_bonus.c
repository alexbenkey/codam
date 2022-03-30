/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/08 21:24:49 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/03/18 15:53:33 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <limits.h>

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
	static char		*lo_ar[OPEN_MAX];
	int				r;
	char			*rl;
	char			*tmp;

	if (BUFFER_SIZE < 1 || read(fd, NULL, 0) < 0)
		return (NULL);
	if (!lo_ar[fd])
		lo_ar[fd] = ft_calloc(BUFFER_SIZE + 1, 1);
	r = read_from_buf(fd, &lo_ar[fd]);
	if (!lo_ar[fd][0])
	{
		if (ft_clear((void **)&lo_ar[fd]))
			return (NULL);
	}
	rl = check_block(lo_ar[fd], r);
	if (!rl)
		return (NULL);
	tmp = ft_substr(lo_ar[fd], ft_strlen(rl), \
	(ft_strlen(lo_ar[fd]) - (ft_strlen(rl))));
	ft_clear((void **)&lo_ar[fd]);
	lo_ar[fd] = tmp;
	if (lo_ar[fd][0] == 0 && r == 0)
		free(lo_ar[fd]);
	return (rl);
}
