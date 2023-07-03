/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 18:54:08 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/10/24 18:54:09 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*btemp;
	int		i;
	int		len;

	btemp = (char *)s;
	i = 0;
	while (s[i] != 0)
		i++;
	len = i;
	i = 0;
	while (i <= len)
	{	
		if (s[i] == (unsigned char)c)
			return (&btemp[i]);
		i++;
	}
	return (0);
}
