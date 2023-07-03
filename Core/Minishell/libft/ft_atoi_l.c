/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi_l.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/11 19:14:05 by avon-ben      #+#    #+#                 */
/*   Updated: 2023/05/11 20:25:41 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	ft_coreatoi(const char *str, int minus, int n)
{
	long int		loops;
	long int		zeros;
	long long int	test;
	long			result;

	result = 0;
	zeros = 1;
	loops = n;
	test = result;
	while ('0' <= str[n] && '9' >= str[n] && test == result)
	{
		result = (result * zeros) + (str[n] - '0');
		test = (test * zeros) + (str[n] - '0');
		if (test != result && (test * -1) != result)
			result = -1;
		zeros = 10;
		n++;
	}
	if (minus == 1 && test != result && (test * -1) != result)
		result = result + 1;
	if (minus == 1 && (test * -1) != result)
		result = result * -1;
	return (result);
}

static int	ft_space(char c)
{
	if (c == ' ')
		return (3);
	if (c >= 9 && c <= 13)
		return (3);
	if (c == '+')
		return (2);
	if (c == '-')
		return (1);
	return (0);
}

long int	ft_atoi_l(const char *str)
{
	long	result;
	int		n;
	int		minus;

	result = 0;
	n = 0;
	minus = 0;
	while (str[n] != '\0')
	{
		if (2 >= ft_space(str[n]))
		{
			if (1 == ft_space(str[n]) || 2 == ft_space(str[n]))
			{
				minus = ft_space(str[n]);
				n++;
			}
			result = ft_coreatoi(str, minus, n);
			return (result);
		}
		n++;
	}
	return (result);
}
