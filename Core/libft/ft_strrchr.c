#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*btemp;
	int		i;

	btemp = (char *)s;
	i = 0;
	while (s[i] != 0)
		i++;
	while (i >= 0)
	{	
		if (s[i] == (unsigned char)c)
			return (&btemp[i]);
		i--;
	}
	return (0);
}
