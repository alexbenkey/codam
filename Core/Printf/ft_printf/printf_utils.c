#include "printf.h"

void	printhex(long n, char c);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	printhex(long n, char c)
{
	char	vals[17];
	int		current;

	if (c == 'X')
		ft_strlcpy(vals, "0123456789ABCDEF", 16);
	if (c == 'x')
		ft_strlcpy(vals, "0123456789abcdef", 16);
	if (n > 0)
	{
		current = n % 16;
		printhex((n / 16), c);
		write (1, &vals[current], 1);
	}
}

void	print_uint(unsigned int n)
{
	if (n > 0)
	{
		
	}
}
