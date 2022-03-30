#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t					i;
	const unsigned char		*tmp_s;

	tmp_s = s;
	i = 0;
	while (i < n)
	{
		if (tmp_s[i] == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (0);
}
