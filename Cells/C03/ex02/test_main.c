#include	<stdio.h>
#include	<string.h>

char	*ft_strcat(char *dest, char *src);

int	main(void)
{
	char	ft_dest[12] = "12345";
	char	ft_src[5]   = "12345";
	char	dest[12]= "12345";
	char	src[5]   = "12345";

	//printf("ft: %s\n", ft_strcat(ft_dest, ft_src));
	printf("string.h: %s\n", strcat(dest, src));
}
