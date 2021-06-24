#include <unistd.h>

void	iterate_second(int a, int b)
{
	int c;
	int d;

	c = a;
	d = b+1;
	while (c < 58) 
	{
		while(d < 58)
		{
			write(1, &a, 1);
			write(1, &b, 1);
			write(1, " ", 1);
			write(1, &c, 1);
			write(1, &d, 1);
			d++;
			if(a <57 || b < 56)
				write(1, ",", 1);
		}
	c++;
	d = 48;
	}
}

void	ft_print_comb2(void)
{
	int a;
	int b; 

	a = 48;
	b = 48;
	while (a < 58)
	{
		while(b < 58)
		{
			iterate_second(a, b);
			b++;
		}
	a++;
	b = 48;	
	}
}	

int	main(void)
{
	ft_print_comb2();
}
