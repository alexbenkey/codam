#include <unistd.h>

void	ft_putchar(char a);

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

void	ft_putchar(char a)
{
	write(1, &a, 1);
}
