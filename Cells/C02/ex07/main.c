#include<stdio.h>

int	ft_strupcase(char *str);

int	main(void)
{
	int a;
	char str[] = "124asdqe1525?';[]";
	a = ft_strupcase(str);
	int count = 0;
	while (str[count])
	{
		printf("%c",str[count]);
		count++;
	}
	printf("%s", str);
}
