#include<stdio.h>

int	main(void)
{
	int	a;
	int b;
	int div;
	int mod; 

	a = 31;
	b = 10;

	ft_div_mod(a, b, &div, &mod);
	printf("%d, %d", div, mod);
}
