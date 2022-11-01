/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 18:53:38 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/10/24 18:53:39 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	if (s != 0)
	{
		i = 0;
		while (s[i])
		{
			if (ft_isascii(s[i]))
				write(fd, &s[i], 1);
			i++;
		}
		write(fd, "\n", 1);
	}
}
