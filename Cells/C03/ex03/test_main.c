#include	<stdio.h>
#include	<string.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb);

int	main(void)
{
	char	ft_dest[15] = "1235";
	char	ft_src[]   = "vier";
	char	dest[15]= "1235";
	char	src[5]   = "vier";
	int		length = 3;

	printf("ft: %s\n", ft_strncat(ft_dest, ft_src, length));
	printf("string.h: %s\n", strncat(dest, src, length));
}
