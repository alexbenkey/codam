/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 18:53:41 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/10/24 18:53:42 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fd_putchar(char c, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		fd_putchar('-', fd);
		fd_putchar('2', fd);
		ft_putnbr_fd(147483648, fd);
	}
	else if (n < 0)
	{
		fd_putchar('-', fd);
		ft_putnbr_fd((n * -1), fd);
	}
	else if (n < 10)
		fd_putchar((n + 48), fd);
	else
	{
		ft_putnbr_fd((n / 10), fd);
		fd_putchar(((n % 10) + 48), fd);
	}
}

static void	fd_putchar(char c, int fd)
{
	write(fd, &c, 1);
}
