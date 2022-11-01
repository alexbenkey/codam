/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 18:49:26 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/10/24 18:49:27 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_val(char type, int *input);

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		i;
	int		j;

	va_start(ptr, str);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == ('%'))
		{
			str++;
			if (str[i] == '%')
				ft_putchar_ret1('%');
			else
				j += (print_val(str[i], va_arg(ptr, int *)) - 1);
		}	
		else
			write(1, &str[i], 1);
		i++;
	}
	va_end(ptr);
	return (i + j);
}

int	print_val(char type, int *input)
{
	int	i;

	i = 0;
	if (type == 'c')
		i = ft_putchar_ret1((char)input);
	if (type == 's')
		i = ft_putstr_strlen((char *)input);
	if (type == 'p')
		i = put_pt((unsigned long long)input);
	if (type == 'd')
		i = nlen_putn((int)input);
	if (type == 'i')
		i = nlen_putn((int)input);
	if (type == 'u')
		i = print_uint((unsigned int)input, 0);
	if (type == 'x')
		i = printhex((int)input, 'x', 0);
	if (type == 'X')
		i = printhex((int)input, 'X', 0);
	return (i);
}
