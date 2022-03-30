#include "libft.h"

void	*ft_memset(char	*mystring, int c, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		mystring[i] = c;
		i++;
	}
	return (mystring);
}
