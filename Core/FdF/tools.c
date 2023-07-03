/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tools.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/18 16:30:32 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/12/02 21:34:44 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	print_map(t_data *data)
{
	int	width;
	int	height;
	int	x;
	int	y;

	width = data->width;
	height = data->height;
	while (y < (height))
	{
		while (x < width)
		{
			ft_printf("%d ", data->points[y][x]);
			x++;
		}
		x = 0;
		ft_printf("\n");
		y++;
	}
}

void	update_coordinates_x(t_data *data, int i)
{
	int		row;
	int		column;

	column = i / data->height;
	row = i % data->height;
	if (row == data->height - 1)
		next_to_next_column_x(data, i);
	else
		next_to_next_row_x(data, i);
}

void	update_coordinates_y(t_data *data, int i)
{
	int		row;
	int		column;

	row = i / data->width;
	column = i % data->width;
	if (column == data->width - 1)
		next_to_next_row_y(data, i);
	else
		next_to_next_column_y(data, i);
}

void	write_text(t_data *data)
{
	int	i;

	i = 0;
	mlx_put_string(data->mlx, "CONTROLS", 30, (HEIGHT -(TXT_HGT - i++ *T_INT)));
	i++;
	mlx_put_string(data->mlx, "Zoom in:     numpad +", \
	30, (HEIGHT -(TXT_HGT - i++ *T_INT)));
	mlx_put_string(data->mlx, "Zoom out:    numpad -", \
	30, (HEIGHT -(TXT_HGT - i++ *T_INT)));
	mlx_put_string(data->mlx, "Move image:  arrow keys (hold)", \
	30, (HEIGHT -(TXT_HGT - i++ *T_INT)));
	mlx_put_string(data->mlx, "Increase elevation by fixed interval: ] ", \
	30, (HEIGHT -(TXT_HGT - i++ *T_INT)));
	mlx_put_string(data->mlx, "Decrease elevation by fixed interval: ] ", \
	30, (HEIGHT -(TXT_HGT - i++ *T_INT)));
	mlx_put_string(data->mlx, "Increase elevation by multiplication: * (hold)", \
	30, (HEIGHT -(TXT_HGT - i++ *T_INT)));
	mlx_put_string(data->mlx, "Increase elevation by multiplication: / (hold)", \
	30, (HEIGHT -(TXT_HGT - i++ *T_INT)));
}
