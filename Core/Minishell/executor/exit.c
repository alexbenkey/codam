/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbax <jbax@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/02 13:18:11 by jbax          #+#    #+#                 */
/*   Updated: 2023/05/08 20:24:35 by jbax          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/all.h"

void	exit_errbug(char *error, char *debug)
{
	ft_putendl_fd(error, 2);
	(void)debug;
	exit(g_exit_code);
}

static int	check_arg(char *arg)
{
	if (*arg == '+' || *arg == '-')
		arg++;
	if (!*arg)
		return (1);
	while (ft_isdigit(*arg))
		arg++;
	if (!*arg)
		return (0);
	return (1);
}

void	ft_exit_builtin(char **arg)
{
	ft_putstr_fd("exit\n", 2);
	if (!arg || !*(&arg[1]))
		exit(g_exit_code);
	if (check_arg(arg[1]))
	{
		if (!arg[2])
		{
			ft_putstr_fd("minishell: exit: ", 2);
			ft_putstr_fd(arg[1], 2);
			ft_putstr_fd(": numeric argument required\n", 2);
			exit(255);
		}
	}
	if (arg[2])
	{
		ft_putstr_fd("minishel: exit: too many arguments\n", 2);
		g_exit_code = 1;
	}
	else
		exit(ft_atoi(arg[1]) % 256);
}
