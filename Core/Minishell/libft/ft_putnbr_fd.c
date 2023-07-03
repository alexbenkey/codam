/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbax <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/26 17:52:46 by jbax          #+#    #+#                 */
/*   Updated: 2020/11/26 18:24:39 by jbax          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			c;
	unsigned int	d;

	d = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		d = n * -1;
	}
	c = d % 10 + '0';
	d = d / 10;
	if (d > 0)
		ft_putnbr_fd(d, fd);
	write(fd, &c, 1);
}
