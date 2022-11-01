/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 18:10:36 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/10/28 15:54:43 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "./src/libft/libft.h"
#include "./src/ft_printf/ft_printf.h"

int		int_to_bin(int i);
void	send_bits(char *string, pid_t serv_pid);
void	split_and_send(char *text, pid_t serv_pid);
void	sig_handler(int sig);
void	error(char *string);

char	g_sigbits[8] = "00000000";

int	int_to_bin(int i)
{
	int		j;

	j = 7;
	{
		while (j > -1)
		{
			if (((i >> j) & 1) == 1)
				g_sigbits[(7 - j)] = '1';
			else
				g_sigbits[(7 - j)] = '0';
			j--;
		}
	}
	return (i);
}

void	split_and_send(char *text, pid_t serv_pid)
{
	int		i;

	i = 0;
	while (text[i])
	{
		int_to_bin(text[i]);
		send_bits(g_sigbits, serv_pid);
		i++;
	}
	send_bits("00000000", serv_pid);
}

void	send_bits(char *string, pid_t serv_pid)
{
	struct sigaction	int_pause;
	int					i;

	i = 0;
	while (string[i])
	{
		if (string[i] == '0')
		{
			if (kill(serv_pid, SIGUSR1) == -1)
				write(1, "\na signal error occured\n", 24);
		}
		else if (string[i] == '1')
		{
			if (kill(serv_pid, SIGUSR2) == -1)
				write(1, "\na signal error occured\n", 24);
		}
		i++;
		//usleep(100);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					serv_pid;
	char				*string;

	sa.sa_handler = &sig_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_NODEFER;
	sigaction(SIGUSR1, &sa, NULL);
	if (argc != 3)
	{
		write(1, "bad input\n", 10);
		exit (0);
	}
	serv_pid = ft_atoi(argv[1]);
	string = (char *)malloc(sizeof(argv[2]));
	ft_memcpy(string, argv[2], ft_strlen(argv[2]));
	if (argc == 3)
	{
		split_and_send(string, serv_pid);
	}
	free(string);
	return (0);
}

void	sig_handler(int sig)
{
	write(1, "message received by server\n", 27);
}
