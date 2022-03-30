#include "libft.h"

int	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (src[i] != 0 && i < (dstsize - 1))
	{
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + i) = '\0';
	while (*(src + i) != 0)
		i++;
	return (i);
}
