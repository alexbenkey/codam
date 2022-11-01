/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 15:02:51 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/10/23 17:32:07 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	p_check(const char *str);
static void	fd_putchar(char c, int fd);

// int	ft_atoi(const char *str)
// {
// 	int	i;
// 	int	p;
// 	int	val;

// 	i = 0;
// 	val = 0;
// 	while ((*str == ' ') || (*str >= 9 && *str <= 13))
// 		str++;
// 	p = p_check(str);
// 	if (*str == '-' || *str == '+')
// 		str++;
// 	while ((str[i] >= 48) && (str[i] <= 57))
// 	{
// 		val *= 10;
// 		val += (str[i] - 48);
// 		i++;
// 		if (i == 19 && str[i] && p == -1)
// 			return (0);
// 		else if (i == 19 && str[i])
// 			return (-1);
// 	}
// 	return (val * p);
// }

// static int	p_check(const char *str)
// {
// 	int	i;
// 	int	p;

// 	p = 1;
// 	i = 0;
// 	while ((*str == ' ') || (*str >= 9 && *str <= 13))
// 		str++;
// 	if (*str == '-' || *str == '+')
// 	{
// 		if (*str == '-')
// 			p *= -1;
// 		str++;
// 	}
// 	return (p);
// }

// static int	ft_countchars(long int n);

// char	*ft_itoa(int n)
// {
// 	char		*s;
// 	int			strlen;
// 	long int	val;

// 	val = n;
// 	strlen = ft_countchars(val);
// 	s = (char *)malloc((strlen + 1) * sizeof(char));
// 	if (s == 0)
// 		return (0);
// 	s[strlen] = '\0';
// 	if (val < 0)
// 	{
// 		val *= -1;
// 		s[0] = '-';
// 	}
// 	if (val == 0)
// 		s[0] = '0';
// 	while (val)
// 	{
// 		strlen--;
// 		s[strlen] = ((val % 10) + 48);
// 		val = val / 10;
// 	}
// 	return (s);
// }

// static int	ft_countchars(long int n)
// {
// 	int	cnt;

// 	cnt = 0;
// 	if (n == 0)
// 		return (1);
// 	if (n == -2147483648)
// 	{
// 		n = (n / 10);
// 		cnt++;
// 	}
// 	if (n < 0)
// 	{
// 		n *= -1;
// 		cnt++;
// 	}
// 	while (n)
// 	{
// 		n = (n / 10);
// 		cnt++;
// 	}
// 	return (cnt);
// }
