#include <stdio.h>
#include <unistd.h>

int		check_val(char c, char *s);
void	print_ints(int *array);
void	array_zeroer(int *array);

int	main(int argc, char **argv)
{
	int 	lookup[128];
	char	*s1;
	char	*s2;
	int		i;

	i = 0;
	s1 = argv[1];
	s2 = argv[2];
	array_zeroer(lookup);
	if (argc == 3)
	{
		while (s1[i] != '\0')
		{
			if (check_val(s1[i], s2))
			{
				if (lookup[s1[i]] == 0)
					write(1, &s1[i], 1);
				lookup[s1[i]] += 1;
			}	
				//printf("val: %i", (int)s2[i]);
			i++;
		}
	}
	write(1, "\n", 1);
}

int	check_val(char c, char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	array_zeroer(int *array)
{
	int i;

	i = 0;
	while (i < 128)
	{
		array[i] = 0;
		i++;
	}
}

void	print_ints(int *array)
{
	int	i;

	i = 0;
	while (i < 128)
	{
		printf("int at place %i= %i\n", i, array[i]);
		i++;
	}
}
