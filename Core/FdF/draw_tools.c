/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_tools.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/02 19:25:52 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/12/02 22:37:40 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	draw_wrapper_pix(t_data *data, double x, double y)
{
	unsigned int	x_adj;
	unsigned int	y_adj;

	x_adj = double_adjuster(x);
	y_adj = double_adjuster(y);
	if (x_adj < WIDTH && x_adj > 0 && y_adj < HEIGHT && y_adj > 0)
		mlx_put_pixel(data->img, x_adj, y_adj, 0xFFFFFF);
}

void	next_to_next_column_x(t_data *data, int i)
{
	double	adjusted;
	int		column;

	column = ((i / data->height) + 1);
	adjusted = data->interval * tan((data->angle) * (PI / 180));
	data->next_x = data->start_x;
	data->next_y = data->start_y;
	data->next_x += (data->interval * column);
	data->next_y += (adjusted * column);
}

void	next_to_next_row_x(t_data *data, int i)
{
	double	adjusted;

	adjusted = data->interval * tan((data->angle) * (PI / 180));
	data->next_x = data->current_x - data->interval;
	data->next_y = data->current_y + adjusted;
}

void	next_to_next_column_y(t_data *data, int i)
{
	double	adjusted;

	adjusted = data->interval * tan((data->angle) * (PI / 180));
	data->next_x = data->current_x + data->interval;
	data->next_y = data->current_y + adjusted;
}

void	next_to_next_row_y(t_data *data, int i)
{
	double	adjusted;
	int		row;

	row = ((i / data->width) + 1);
	adjusted = data->interval * tan((data->angle) * (PI / 180));
	data->next_x = data->start_x;
	data->next_y = data->start_y;
	data->next_x = data->next_x - (data->interval * row);
	data->next_y = data->next_y + (adjusted * row);
}
