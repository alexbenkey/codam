#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


void	ft_putchar(char c);
void	ft_putstr(char *str);
void	get_digit(int	*input);
int    ft_strcmp(int *input, int *len);
void check_error(char *input, int *len);



// void ft_len(int len); // get string length
// void ft_pustr(char c, char str); // print a string
// void check_error(char *str); // print the error message

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}


void check_error(char *input, int *len)
{
    if (*input < 0 || *input >= 4294967295)
    {
		ft_putstr("Error\n");
		exit(1);
	}
}

void	get_digit(int	*input)
{
	int	part1;
	int	part2;

	if (*input > 99)
	{
		part1 = *input / 100;
		part2 = *input / 10
		part3 = *input % 100;

	}
}

int	ft_len(int *input)
{

	int i;
	int *len;
	char *str;
	
	i = 0;


	while (input[i])
	{
		i++;
	}
	return (i);
	*len = i;
}

int    ft_strcmp(int *input, int *len)
{
	int key[32] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 30, 40, 50, 60, 70, 80, 90, 100, 1000, 1000000, 1000000000};
	char* digit[20] = {"zero", "one", "two",  "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen",  "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
	char* tens[10]= { "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
	char* tens_power[4] = {"hundred", "thousand", "million", "billion"};

int i = 0;

if (*input < 20)
{
	while (key[i] != *input)
		{  
			i++;
		}
		ft_putstr(digit[i]);
return ('\n');
}

if ((*input > 19) && (*input < 91))
{
	while (key[i] != (*input / 10))
		{  
			i++;
		}
		ft_putstr(tens[i]);
return ('\n');
}


if (*input > 99)
{
	while (*input >= 99 && *input <= 4294967295)
	{
		*input = *input * 10;
		*input = *input + *str - '0';
		str++;
	}
	return (number);
}
	
}
return 0;
}


int main(void)
{
	int input = 100;
	// check_error(char *str);
	int *len;
	*len = (ft_len(&input));
	ft_strcmp(&input, len);

}