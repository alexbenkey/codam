/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gnl.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/29 22:43:52 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/10/29 23:08:21 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

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

char	*check_block(char *lo, int r)
{
	char	*rl;

	if (lo[0] == '\n')
		rl = ft_substr(lo, 0, 1);
	else if (r == -1)
		rl = ft_strdup(lo);
	else if (gnl_strchr(lo, '\n') && gnl_strchr(lo, '\n') != (ft_strlen(lo)))
		rl = ft_substr(lo, 0, (gnl_strchr(lo, '\n') + 1));
	else
		rl = NULL;
	return (rl);
}

int	read_from_buf(int fd, char **leftovers)
{
	char	*temp;
	char	read_str[BUFFER_SIZE + 1];
	int		r;

	while (gnl_strchr(*leftovers, '\n') == -1)
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

int	gnl_strchr(const char *s, int c)
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