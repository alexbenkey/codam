/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   signals.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbax <jbax@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 14:42:30 by jbax          #+#    #+#                 */
/*   Updated: 2023/05/08 15:37:49 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/all.h"

void	sighandler_parent(int signum)
{
	if (signum == SIGINT)
	{
		rl_replace_line("", 0);
		write(1, "\n", 2);
		rl_on_new_line();
		rl_redisplay();
		g_exit_code = 1;
	}
	if (signum == SIGQUIT)
	{
	}
}

void	set_signal_parrent(void)
{
	signal(SIGINT, sighandler_parent);
	signal(SIGQUIT, sighandler_parent);
}

void	block_signal(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

void	reset_signal(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}
