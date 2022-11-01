/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 18:52:10 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/10/24 18:52:11 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countchars(long int n);

char	*ft_itoa(int n)
{
	char		*s;
	int			strlen;
	long int	val;

	val = n;
	strlen = ft_countchars(val);
	s = (char *)malloc((strlen + 1) * sizeof(char));
	if (s == 0)
		return (0);
	s[strlen] = '\0';
	if (val < 0)
	{
		val *= -1;
		s[0] = '-';
	}
	if (val == 0)
		s[0] = '0';
	while (val)
	{
		strlen--;
		s[strlen] = ((val % 10) + 48);
		val = val / 10;
	}
	return (s);
}

static int	ft_countchars(long int n)
{
	int	cnt;

	cnt = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
	{
		n = (n / 10);
		cnt++;
	}
	if (n < 0)
	{
		n *= -1;
		cnt++;
	}
	while (n)
	{
		n = (n / 10);
		cnt++;
	}
	return (cnt);
}
