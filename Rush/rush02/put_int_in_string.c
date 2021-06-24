#include <stdio.h>

void	put_int_in_string(char *str, int *array)
{
	int index;
	int counter;
	int	number;
	int test;

	counter = 0;
	index = 0;
	while (str[index] != '\0')
	{
		while (str[index] < '0' || str[index] > '9')
			index++;
		number = 0;
		while (str[index] >= '0' && str[index] <= '9')
		{
			number = number * 10;
			number = number + str[index] - '0';
			index++;
		}
		array[counter] = number;
		counter++;
		array[counter] = '\0';
	}
	test = 0;
	while (array[test] != '\0')
}
