#include "get_next_line.h"

int	main(int argc, char **argv)
{
	char	*buf;
	int		fd;
	int		i;

	i = 10;
	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		while (i)
		{
			buf = get_next_line(fd);
			if (buf != NULL)
			{
				printf("\nmain output: %s \n", buf);
				free(buf);
			}
			if (buf == NULL)
				printf("Nothing to read.");
			i--;
		}
		close(fd);
	}
	else
		printf("no file to read from.\n");
}
