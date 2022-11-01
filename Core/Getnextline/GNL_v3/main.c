#include "get_next_line.h"	

int	main(int argc, char **argv)
{
	char	*buf;
	int		fd;
	int		i;

	i = 20;
	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		while (i)
		{
			buf = get_next_line(fd);
			printf("\nmain output: %s \n", buf);
			i--;
			free(buf);
		}	
		close(fd);
	}
	else
		printf("no file to read from.\n");
}
