/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jordan <jordan@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/01 16:46:23 by jordan        #+#    #+#                 */
/*   Updated: 2021/04/26 17:42:52 by jbax          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_core(int count, int negatief, int n)
{
	char	*dest;
	int		temp;

	dest = malloc((count + negatief + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	dest[count + negatief] = '\0';
	if (negatief == 1)
		dest[0] = '-';
	negatief = negatief - 1;
	while (count != 0)
	{
		temp = n % 10;
		n = n / 10;
		if (negatief == 0)
			temp = temp * -1;
		dest[count + negatief] = temp + '0';
		count--;
	}
	return (dest);
}

char	*ft_itoa(int n)
{
	char	*dest;
	int		negatief;
	int		temp;
	int		count;

	count = 0;
	temp = n;
	negatief = 0;
	if (n < 0)
		negatief = 1;
	while (temp != 0)
	{
		temp = temp / 10;
		count++;
	}
	if (count == 0)
		count = 1;
	dest = ft_core(count, negatief, n);
	if (dest == NULL)
		return (NULL);
	return (dest);
}
