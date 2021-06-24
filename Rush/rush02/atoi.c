#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		error(char *err);

int	ft_valid_number(char *str)
{
	int	number;

	number = 0;
	while (*str >= '0' && *str <= '9')
	{
		number = number * 10;
		number = number + *str - '0';
		str++;
	}
	return (number);
}

int	main(int argc, char **argv)
{
	int	nb;

	nb = 0;
	if (argc != 2 && argc != 3)
		return (error("Error"));
	else if (argc == 2)
		nb = ft_valid_number(argv[1]);
	printf("argc: %d\n", argc);
	printf("argv: %s\n", argv[1]);
	return (0);
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	error(char *err)
{
	ft_putstr(err);
	return (0);
}