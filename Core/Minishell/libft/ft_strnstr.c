/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbax <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/13 09:35:57 by jbax          #+#    #+#                 */
/*   Updated: 2021/12/10 16:45:33 by jbax          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	count;
	unsigned int	count2;

	count = 0;
	count2 = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (count < len && *haystack != '\0')
	{
		while (haystack[count2] == needle[count2] && (count + count2) < len)
		{
			count2++;
			if (needle[count2] == '\0')
				return ((char *)haystack);
		}
		count2 = 0;
		haystack++;
		count++;
	}
	return (NULL);
}
