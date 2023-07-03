/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jordan <jordan@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/15 14:38:58 by jordan        #+#    #+#                 */
/*   Updated: 2021/03/25 12:45:20 by jbax          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	count;

	count = 0;
	if (size > 0)
	{
		while (src[count] != '\0' && count < (size - 1))
		{
			dst[count] = src[count];
			count++;
		}
		dst[count] = '\0';
	}
	return (ft_strlen(src));
}
