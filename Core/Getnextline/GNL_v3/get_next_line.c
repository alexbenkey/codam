#include "get_next_line.h"

int	ft_clear(void **ptr)
{
	if (*ptr)
	{
		ft_memset(*ptr, 0, ft_strlen(*ptr));
		free(*ptr);
		*ptr = 0;
		return (1);
	}
	return (0);
}

void	*ft_memset(void *mystring, int c, size_t len)
{
	unsigned char	*ub;

	ub = (unsigned char *)b;
	while (len > 0)
	{
		*ub = c;
		len--;
		ub--;
	}
	return (b);
}

char	*get_next_line(int fd)
{
	int			r;
	char		buf[BUFFER_SIZE + 1];
	static char	*leftovers = NULL;
	//char		*ret_line;
	char		*tmp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!leftovers)
		leftovers = ft_calloc(BUFFER_SIZE + 1, 1);
	while (!ft_strchr(leftovers, '\n'))
	{
		r = read(fd, buf, BUFFER_SIZE);
		buf[r] = '\0';
		tmp = ft_strjoin(leftovers, buf);
		ft_clear((void **)&ret_line);
		ret_line = tmp;
		if (r < 1)
			break ;
	}
	if (r == 0)
		line = ft_strdup(leftovers);
	else if (r > 0)
		line = ft_substr(leftovers, 0, (ft_strchr(leftovers, '\n')));
	else
		return (NULL);
	if (r > 0)
		r = +1;
	else
		r += 0;
	tmp = ft_strdup(leftovers + (ft_strlen(line) + r));
	ft_clear((void **)&leftovers);
	leftovers = tmp;
tr	return (line);
}
