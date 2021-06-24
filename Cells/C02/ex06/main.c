#include<stdio.h>

int	ft_str_is_printable(char *str);

int	main(void)
{
	int a;
	char str[] = "asdqe";
	a = ft_str_is_printable(str);
	printf("%d", a);
}