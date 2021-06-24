#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#define BUF_SIZE 470

void	ft_putchar(char c);
void	ft_putstr(char *str);

int 	main(void)
{
	int 	y = 0;
	char 	array[20][20];
	int 	i = 0;
	int		map;
	int		input_map;
	int		return_rd;
	char	buf[BUF_SIZE + 1];


	map = open("map", O_RDWR);
	if (map == -1)
		ft_putstr("error opening the file");
	else if (map > 0)
	{
		ft_putstr("the file was opened succesfully.\nThe return value is:  ");
		ft_putchar(map + '0');
		ft_putchar('\n');
	}
	return_rd = (read(map, buf, BUF_SIZE));
	buf[return_rd] = '\0';
	// ft_putstr(buf);
	// while (buf[i] != '\n')
	// {
	// 	ft_putchar(buf[i]);
	// 	i++;
	// }
	while (buf[i] != '\n')
	{
		array[i][0] = buf[i];
		i++;
	}
	while (array[i][0])
		{
		ft_putchar(array[i][0]);
		i++;
		}
	if (close(map) == -1)
	{
		ft_putstr("error closing the file");
		return (1);
	}
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}
