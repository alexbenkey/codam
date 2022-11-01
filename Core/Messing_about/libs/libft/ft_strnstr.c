#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	it_needle;
	size_t	it_haystack;

	it_needle = 0;
	it_haystack = 0;
	if (needle[0] == 0)
		return ((char *)haystack);
	while (haystack[it_haystack] && (it_haystack < len))
	{
		while (needle[it_needle] == haystack[it_needle + it_haystack])
		{
			it_needle++;
			if (it_needle + it_haystack > len)
				return (0);
			if (needle[it_needle] == '\0')
				return ((char *)haystack + it_haystack);
		}
		it_needle = 0;
		it_haystack++;
	}
	return (0);
}
