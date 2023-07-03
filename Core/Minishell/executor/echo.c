/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   echo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbax <jbax@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/23 17:22:51 by jbax          #+#    #+#                 */
/*   Updated: 2023/03/22 18:35:37 by jbax          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

static int	has_option(char *arg)
{
	if (!arg || !*arg)
		return (1);
	if (*arg != '-')
		return (0);
	arg++;
	while (*arg)
	{
		if (*arg != 'n')
			return (0);
		arg++;
	}
	return (1);
}

void	ft_echo(char **arg, int output_fd)
{
	int	option;

	option = 0;
	while (*arg && has_option(*arg))
	{
		option = 1;
		arg++;
	}
	while (*arg)
	{
		ft_putstr_fd(*arg, output_fd);
		if (arg[1])
			write(output_fd, " ", 1);
		arg++;
	}
	if (!option)
		write(output_fd, "\n", 1);
}
