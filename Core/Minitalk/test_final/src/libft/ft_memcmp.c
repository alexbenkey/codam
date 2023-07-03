/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 18:53:01 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/10/24 18:53:02 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char		*s1_temp;
	unsigned char		*s2_temp;
	size_t				i;

	s1_temp = (unsigned char *)s1;
	s2_temp = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if ((s1_temp[i]) != (s2_temp[i]))
			return ((s1_temp[i]) - (s2_temp[i]));
		i++;
	}
	return (0);
}
