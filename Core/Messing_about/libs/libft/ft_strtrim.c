#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	end;

	if (!s1 || !set)
		return (ft_strdup(""));
	end = (ft_strlen(s1));
	i = 0;
	while (ft_memchr(set, s1[i], ft_strlen(set)))
		i++;
	if (i != end)
	{
		while (ft_memchr(set, s1[(end - 1)], (ft_strlen(set))))
			end--;
	}
	return (ft_substr(s1, i, (end - i)));
}
