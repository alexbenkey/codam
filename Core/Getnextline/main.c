#include "get_next_line.h"

int	main(void)
{
	//int 	i = 0;
	int		fd;
	fd = open("testfile", O_RDONLY);
	//static int BUFFSIZE = 100;
	//char *buffer = (char *) malloc((BUFFSIZE) * sizeof(char));
	//read(fd, buffer, BUFFSIZE);
	//temp = split_nl(buffer);
	//buffer[BUFFSIZE] = '\0';
	//printf("\nbuffer: %s", temp);
	//printf("text: %zd\n", read(fd, buffer, BUFFSIZE));
	//ft_putstr(buffer);
	// while (i <= 5)
	// {
	// 	printf("line %d: %s", i, get_next_line(fd));
	// 	i++;
	// }
	get_next_line(fd); 
	close(fd);
}
