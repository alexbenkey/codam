#include "get_next_line.h"

void	ft_putstr(char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		write(1, &string[i], 1);
		i++;
	}
}

int	check_malloc(char *mem)
{
	if (!mem)
	{
		free(mem);
		return (0);
	}
	return (1);
}

char	*trim_start(char *buffer, int i)
{
	int	j;

	j = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	while (buffer[i])
	{
		i++;
		buffer[j] = buffer[i];
		j++;
	}
	buffer[j] = '\0';
	return (buffer);
}

char	*trim_end(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	//if (buffer[i] == '\n')
	buffer[i] = '\0';
	return (buffer);
}

char	*gnl_memset(char *origin, char *destination)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (destination[j])
		j++;
	while (origin[i])
	{
		destination[j] = origin[i];
		i++;
		j++;
	}
	destination[j] = '\0';
	//printf("\ndestination: %s", destination);
	return (destination);
}

int	get_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
