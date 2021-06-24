#include<stdio.h>

int	main(void)
{
	int	a;
	int b;

	a = 31;
	b = 10;

	ft_ultimate_div_mod(&a, &b);
	printf("%d, %d", a, b);
}
