#include<stdio.h>

int	ft_str_is_lowercase(char *str);

int	main(void)
{
	int a;
	char str[] = "asdAASFhuasf";
	a = ft_str_is_lowercase(str);
	printf("%d", a);
}