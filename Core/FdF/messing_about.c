#include <stdio.h>

int	double_adjuster(float value);

int	main(void)
{
	float	f;
	float	m;
	int		i;
	int		fti;
	int		ret_int;

	f = 1.6;
	fti = f;
	i = f / fti;
	m = f - i;
	printf("float value %f\n", f);
	printf("float conversion to int: %i\n", fti);
	printf("f %% 1 (to float): %f\n", m);
	printf("f (float)%f / 1 =  %i (int)\n", f, i);
	ret_int = double_adjuster(3.49124);
	printf("return int: %i", ret_int);
}

int	double_adjuster(float value)
{
	int	y;
	int	int_cpy;

	int_cpy = value;
	printf("int_cpy (%d) converted from value (%f)\n", int_cpy, value);
	if ((value - int_cpy) >= 0.5)
		y = int_cpy + 1;
	else
		y = int_cpy;
	return (y);
}
