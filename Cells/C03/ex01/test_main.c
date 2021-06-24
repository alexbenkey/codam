#include	<stdio.h>
#include	<string.h>

int	ft_strncmp(char *str1, char *str2, unsigned int n);

int	main(void)
{
	char	test1[]	= "hellt";
	char	test2[] = "hello world";
	int		length = 4;

	printf("ft: %d\n", ft_strncmp(test1, test2, length));
	printf("string.h: %d\n", strncmp(test1, test2, length));
}
