#include<stdio.h>

int	main(void)
{
	int	a;
	int b;
	a = 30;
	b = 20;

	ft_swap(&a, &b);
	printf("%d, %d", a, b);
}
