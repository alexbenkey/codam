#include<stdio.h>

int	ft_str_is_uppercase(char *str);

int	main(void)
{
	int a;
	char str[] = "ADASFAEF";
	a = ft_str_is_uppercase(str);
	printf("%d", a);
}