#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>


void	ft_check_string_for_val(char *str, char t);
void	ft_putstr(char *str);
void	ft_putchar(char c);
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