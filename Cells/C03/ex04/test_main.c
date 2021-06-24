#include	<stdio.h>
#include	<string.h>

char	*ft_strstr(char *str, char *to_find);

int	main(void)
{
	char	*ft_haystack   	= "Ontwaak verworwaaktpenen der aarde";
	char	*needle			= "waakt";
	char	*haystack   	= "Ontwaak verwowaaktrpenen der aarde";

	printf("ft: %s\n", ft_strstr(ft_haystack, needle));
	printf("string.h: %s\n", strstr(haystack, needle));
}
