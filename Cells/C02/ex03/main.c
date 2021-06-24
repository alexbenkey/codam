#include<stdio.h>

int	ft_str_is_numeric(char *str);

int	main(void)
{
	int a;
	char str[] = "";
	a = ft_str_is_numeric(str);
	printf("%d", a);
}