#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*tmpdst;
	char		*tmpsrc;

	tmpsrc = (char *)src;
	tmpdst = (char *)dst;
	i = 0;
	if (src == 0 && dst == 0)
		return (0);
	while (i < n)
	{
		tmpdst[i] = tmpsrc[i];
		i++;
	}
	return (dst);
}
