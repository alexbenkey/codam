/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jordan <jordan@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/14 13:19:46 by jordan        #+#    #+#                 */
/*   Updated: 2021/03/25 12:46:00 by jbax          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	count;
	unsigned int	dstlen;

	dstlen = ft_strlen(dst);
	count = 0;
	if (size > 0 && dstlen < size)
	{
		while (src[count] != '\0' && count < (size - dstlen - 1))
		{
			dst[count + dstlen] = src[count];
			count++;
		}
		dst[count + dstlen] = '\0';
		if (dst[count + dstlen] != '\0')
			return (size);
	}
	else
		return (ft_strlen(src) + size);
	return (ft_strlen(src) + dstlen);
}
