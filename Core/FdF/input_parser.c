/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_parser.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/02 18:58:53 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/12/02 22:20:05 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

t_data	*get_map(char *path, t_data *data)
{
	int		fd;
	char	*line;
	int		y;

	y = 0;
	if (!path)
		error_exit();
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		put_map_data(line, data, y);
		line = get_next_line(fd);
		y++;
	}
	data->height = y;
	return (data);
}

void	put_map_data(char *line, t_data *data, int y)
{
	int			x;
	char		**splitted;
	char		**spl_ret;
	int			len;

	x = 0;
	splitted = ft_split(line, ' ');
	len = get_len(splitted);
	if (data->width < len)
		data->width = len;
	add_row(data, y, len);
	while (x < len)
	{
		if (has_char(splitted[x], ','))
		{
			spl_ret = ft_split(splitted[x], ',');
			splitted[x] = spl_ret[0];
		}
		data->points[y][x] = get_z_val(splitted[x]);
		x++;
	}
}

void	add_row(t_data *data, int y, int len)
{
	int		**new;
	int		i;
	int		test;
	char	c;

	i = 0;
	new = (int **)malloc(sizeof(int *) * (y + 1));
	if (y == 0)
	{
		new[0] = (int *)malloc(sizeof(int) * len);
		data->points = new;
		return ;
	}
	else
	{
		while (i < y)
		{
			new[i] = data->points[i];
			i++;
		}
	}
	free (data->points);
	new[i] = (int *)malloc(sizeof(int) * len);
	data->points = new;
}

void	error_exit(void)
{
	write(1, "error!\n", 7);
	exit (0);
}

int	get_len(char **splitted)
{
	int	i;

	i = 0;
	while (splitted[i])
		i++;
	return (i);
}
