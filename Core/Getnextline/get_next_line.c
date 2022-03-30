#include "get_next_line.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	char	*str;

	str = (char *)malloc(elsize * nelem);
	if (!str)
		return (NULL);
	ft_bzero(str, (elsize * nelem));
	return (str);
}

void	ft_bzero(char *mystring, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		mystring[i] = 0;
		i++;
	}
}

int	check_for_nl(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[0] == '\n')
			return (-1);
		if (buffer[i] == '\n' || buffer[i] == '\0')
			return (i);
		i++;
	}
	return (0);
}

char	*make_return(char *string, int end)
{
	int		i;
	char	*ret_val;

	i = 0;
	ret_val = malloc(255);
	i = check_for_nl(string);
	printf("%i", i);
	if ((i != 0) || !end)
	{
		gnl_memset(string, ret_val);
		trim_start(string, 0);
		trim_end(ret_val);
	}
	return (ret_val);
}

char	*get_next_line(int fd)
{
	char		*tmp_buf;
	static char	*total = NULL;
	char		*ret_val;
	int			end;

	end = 1;
	tmp_buf = ft_calloc(BUFFER_SIZE, 1);
	if (!check_malloc(tmp_buf))
		return (0);
	if (!total)
		total = ft_calloc(1000, 1);
	while (!check_for_nl(total) && end)
	{
		end = read(fd, tmp_buf, BUFFER_SIZE);
		gnl_memset(tmp_buf, total);
		ft_bzero(tmp_buf, get_len(tmp_buf));
	}
	ret_val = make_return(total, end);
	if (!ret_val)
		return (NULL);
	free(tmp_buf);
	if (!end)
		free(total);
	return (ret_val);
}
