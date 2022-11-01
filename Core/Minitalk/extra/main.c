/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 17:27:55 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/10/13 19:30:49 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	int	pid;

	pid = fork();
	if (pid == -1)
	{
		write(1, "for failed\n", 11);
	}
	if (pid == 0)
	{
		while (1)
		{
			write(1, "child process running\n", 22);
			usleep(50000);
		}
	}
	if (pid > 0)
	{
		sleep(1);
		kill(pid, SIGKILL);
		write(1, "signal killed\n", 14);
		wait(0);
	}
	ft_putnbr_fd(pid, 1);
	return (0);
}
