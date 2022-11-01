#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int 	lookup[128];
	char	*s1;
	char	*s2;
	int		i;

	i = 0;
	s1 = argv[1];
	s2 = argv[2];
	while (i < 128)
	{
		lookup[i] = 0;
		i++;
	}
	i = 0;
	if (argc == 3)
	{
		while (s1[i] != '\0')
		{
			if (lookup[s1[i]] == 0)
				write(1, &s1[i], 1);
			lookup[s1[i]] += 1;
			i++;
		}
		i = 0;
		while (s2[i] != '\0')
		{
			if (lookup[s2[i]] == 0)
				write(1, &s2[i], 1);
			lookup[s2[i]] += 1;
			i++;
		}
	}
	write(1, "\n", 1);
}
