#include "libft.h"

void	ft_bzero(char	*mystring, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		mystring[i] = 0;
		i++;
	}
}
