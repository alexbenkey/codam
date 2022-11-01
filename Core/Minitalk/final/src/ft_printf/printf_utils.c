/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 18:49:54 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/10/24 18:49:55 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_ret1(char c)
{
	return (write(1, &c, 1));
}

int	printhex(long long n, char c, int i)
{
	char	vals[17];
	int		current;

	if (c == 'X')
		ft_strlcpy(vals, "0123456789ABCDEF", 17);
	if (c == 'x')
		ft_strlcpy(vals, "0123456789abcdef", 17);
	if (n < 0)
		n = (2147483647 + (2147483649 - (n * -1)));
	if (n > 0)
	{
		i++;
		current = n % 16;
		i = printhex((n / 16), c, i);
		write (1, &vals[current], 1);
	}
	if (n == 0 && i == 0)
	{
		write (1, &vals[n], 1);
		i++;
	}
	return (i);
}

int	printhex_mod(unsigned long n, char c, int i)
{
	char	vals[17];
	int		current;

	if (c == 'X')
		ft_strlcpy(vals, "0123456789ABCDEF", 17);
	if (c == 'x')
		ft_strlcpy(vals, "0123456789abcdef", 17);
	if (n < 0)
		n = (2147483647 + (2147483647 - (n * -1)));
	if (n > 0)
	{
		i++;
		current = n % 16;
		i = printhex((n / 16), c, i);
		write (1, &vals[current], 1);
	}
	if (n == 0 && i == 0)
	{
		write (1, &vals[n], 1);
		i++;
	}
	return (i);
}

int	print_uint(unsigned int n, int i)
{
	unsigned int	current;

	if (n > 0)
	{
		i++;
		current = n % 10;
		i = print_uint((n / 10), i);
		ft_putchar_ret1(current + 48);
	}
	if (n == 0 && i == 0)
		i = ft_putchar_ret1('0');
	return (i);
}

int	put_pt(unsigned long long input)
{
	int	i;

	i = 0;
	i += (ft_putstr_strlen("0x"));
	i += printhex_mod((unsigned long long)input, 'x', 0);
	return (i);
}
