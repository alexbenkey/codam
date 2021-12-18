#include "get_next_line.h"

char	*get_next_line(int fd);
void	ft_putstr(char *string);
int		get_line_length(int fd);
int		get_buf_len(char *string);
char	*split_nl(char *buffer, int buf_size);

// char	*split_nl(char *string)
// {
// 	int		i;
// 	int		j;
// 	int		len;
// 	char	*returnstr;

// 	i = 0;
// 	j = 0;
// 	while (string[i] != '\n')
// 	{
// 		returnstr[i] = string[i];
// 		i++;
// 	}
// 	i++;
// 	len = get_buf_len(&string[i]);
// 	returnstr = (char *) malloc(len);
// 	while (string[i] && j <= len)
// 	{
// 		returnstr[j] = string[i];
// 		i++;
// 		j++;
// 	}
// 	returnstr[j] = '\0';
// 	return (returnstr);
// }

char	*split_nl(char *buffer, int buf_size, int *i)
{
	char	*return_line;

	return_line = (char *) malloc(buf_size * sizeof(char));
	while (buffer[i] != '\n')
	{
		return_line[i] = buffer[i];
		i++;
	}
	i++;
	return_line[i] = '\n';
}

int	get_buf_len(char *string)
{
	int	i;

	i = 0;
	while (string[i])
		i++;
	printf("\ni: %d", i);
	return (i);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line[BUFFER_SIZE];

	buffer = (char *) malloc(BUFFER_SIZE * sizeof(char));
	if (!buffer)
		free(buffer);
	printf("empty buffer: %s", buffer);
	read(fd, buffer, BUFFER_SIZE);
	printf("full buffer: %s", buffer);
	//line = split_nl(buffer);
	return ((char *) 'i');
}
