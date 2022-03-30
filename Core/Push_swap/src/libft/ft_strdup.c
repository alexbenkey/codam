#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*newstr;

	i = 0;
	while (s[i])
		i++;
	newstr = malloc((i + 1) * sizeof(char));
	if (newstr == 0)
		return (NULL);
	i = 0;
	while (s[i])
	{
		newstr[i] = s[i];
		i++;
	}
	newstr[i] = '\0';
	return ((char *)newstr);
}
