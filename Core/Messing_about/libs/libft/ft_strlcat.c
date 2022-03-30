#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	index_src;
	size_t	index_dst;
	size_t	attempt_len;

	index_src = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	index_dst = ft_strlen(dst);
	if (dstsize > ft_strlen(dst))
		attempt_len = (ft_strlen(src) + ft_strlen(dst));
	else
		return (ft_strlen(src) + dstsize);
	while (index_dst < (dstsize - 1) && src[index_src])
	{
		dst[index_dst] = src[index_src];
		index_src++;
		index_dst++;
	}
	dst[index_dst] = 0;
	return (attempt_len);
}
