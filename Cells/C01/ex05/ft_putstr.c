#include<unistd.h>

void	ft_putchar(char a);

void	ft_putstr(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		ft_putchar(str[index]);
		index++;
	}
}

void 	ft_putchar(char a)
{
	write(1, &a, 1);
}
