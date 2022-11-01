#include "minitalk.h"

int		int_to_bin(int i);
void	send_bits(char *string, pid_t serv_pid);
void	split_and_send(char *text, pid_t serv_pid);

char g_sigbits[8] = "00000000";

int	main(int argc, char **argv)
{
	int		serv_pid;
	char	*string;
	//char	*bits;

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
		split_and_send(argv[2], serv_pid);
	}
	return (0);
}

int	int_to_bin(int i)
{
	//char	*bits;
	int		j;

	//bits = ft_strdup("00000000");
	//if (!bits)
	//	return (-1);
	j = 7;
	if (i < 0 || i > 255)
	{
		write(1, "bad int: ", 9);
		ft_printf("%d", i);
	}
	if (i == 128)
		g_sigbits[0] = '1';
	if (i > 0 && i < 128)
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
	//printf("argv[2][0]: %d, corresponds to character: %c\n", i, i);
	//return (bits);
}

void	split_and_send(char *text, pid_t serv_pid)
{
	int		i;
	//char	*bits;

	i = 0;
	//exit(0);
	//bits = int_to_bin(ft_strlen(text));
	int_to_bin(ft_strlen(text));
	send_bits(g_sigbits, serv_pid);
	usleep(1000);
	while (text[i])
	{
		//bits = int_to_bin(text[i]);
		int_to_bin(text[i]);
		usleep(1000);
		send_bits(g_sigbits, serv_pid);
		i++;
	}
}

void	send_bits(char *string, pid_t serv_pid)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == '0')
			kill(serv_pid, SIGUSR1);
		else if (string[i] == '1')
			kill(serv_pid, SIGUSR2);
		i++;
		usleep(500);
	}
}
