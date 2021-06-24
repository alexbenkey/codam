#include<stdio.h>

int	ft_str_is_alpha(char *str);

int main(void)
{
	int a;
	char str[] = "";
	a = ft_str_is_alpha(str); 
	printf("%d", a);
}
