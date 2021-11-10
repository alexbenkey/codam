#include "printf.h"

void	print_val(char type, int *input);

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		i;

	va_start(ptr, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '%')
				write(1, &str[i], 1);
			else
				print_val(str[i], va_arg(ptr, int *));
		}	
		else
			write(1, &str[i], 1);
		i++;
	}
	va_end(ptr);
	return (1);
}

void	print_val(char type, int *input)
{
	if (type == 'c')
		write(1, &input, 1);
	if (type == 's')
		ft_putstr_fd((char *)input, 1);
	if (type == 'p')
		ft_putstr_fd((char *)&input, 1);
	if (type == 'd')
		ft_putchar((char)input + 48);
	if (type == 'i')
		ft_putnbr_fd((int)input, 1);
	// if (type == 'u')
	if (type == 'x')
		printhex((int)input, 'x');
	if (type == 'X')
		printhex((int)input, 'X');
}

int	main(void)
{	
	char	c = 'h';
	char	s[] = "lalala";
	void 	*p;
	int		d = 5;
	int		i = 123;
	unsigned int u = 4294967295;
	p = &i;

	ft_printf("hello %% %c %s %d %i %p %x %X\nWorld\n", c, s, d, i, p, i, i);
	printf("hello %% %c %s %d %i %u %p %x %X\nWorld\n", c, s, d, i, u, p, i, i);
}
