/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 18:51:28 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/10/24 18:51:29 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	p_check(const char *str);

int	ft_atoi(const char *str)
{
	int	i;
	int	p;
	int	val;

	i = 0;
	val = 0;
	while ((*str == ' ') || (*str >= 9 && *str <= 13))
		str++;
	p = p_check(str);
	if (*str == '-' || *str == '+')
		str++;
	while ((str[i] >= 48) && (str[i] <= 57))
	{
		val *= 10;
		val += (str[i] - 48);
		i++;
		if (i == 19 && str[i] && p == -1)
			return (0);
		else if (i == 19 && str[i])
			return (-1);
	}
	return (val * p);
}

static int	p_check(const char *str)
{
	int	i;
	int	p;

	p = 1;
	i = 0;
	while ((*str == ' ') || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			p *= -1;
		str++;
	}
	return (p);
}
