#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	char	*str;

	str = (char *)malloc(elsize * nelem);
	if (str == 0)
		return (NULL);
	ft_bzero(str, (elsize * nelem));
	return (str);
}
