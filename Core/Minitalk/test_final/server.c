/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 18:24:47 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/10/27 16:51:51 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "./src/libft/libft.h"
#include "./src/ft_printf/ft_printf.h"
#include <sys/wait.h>

long	get_len(int i, int sig);
int		fill_buff(int i, int sig, char *buffer);
void	read_buf(char *buffer, int length);
void	sig_handler(int sig, siginfo_t *si, void *context);
void	error(void);

char	g_siglen[8] = "00000000";

int	main(void)
{
	struct sigaction	sa;
	pid_t				client_pid;
	pid_t				server_pid;
	int					i;
	char				c;

	sa.sa_sigaction = &sig_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	server_pid = getpid();
	i = 0;
	ft_printf("server pid: %d\n", server_pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}

int	btoi(void)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (i < 8)
	{
		total *= 2;
		if (g_siglen[i] == '1')
			total += 1;
		i++;
	}
	return (total);
}

long	get_len(int i, int sig)
{
	unsigned long	val;
	char			*buffer;

	if (sig == SIGUSR1)
		g_siglen[(i % 8)] = '0';
	if (sig == SIGUSR2)
		g_siglen[(i % 8)] = '1';
	if ((i % 8) == 7)
	{
		val = btoi();
		return (val);
	}
	return (-1);
}

void	sig_handler(int sig, siginfo_t *si, void *context)
{
	static int			client_pid;
	static int			i = 0;
	static int			val = -1;

	(void)context;
	client_pid = si->si_pid;
	val = get_len(i++, sig);
	if (val == 0)
	{
		write(1, "\n", 1);
		if (kill(client_pid, SIGUSR1) == -1)
			error();
	}
	if ((i % 8) == 0)
		write(1, &val, 1);
}

void	error(void)
{
	write(1, "\na signal error occured\n", 24);
}
