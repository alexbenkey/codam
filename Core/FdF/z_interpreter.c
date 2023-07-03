/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   z_interpreter.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/02 19:03:23 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/12/02 20:26:31 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	adjust_for_z_y(t_data *data, t_two_points *ttp, int i)
{
	int	x;
	int	y;

	y = i % data->width;
	x = i / data->width;
	ttp->x1 = data->current_x;
	ttp->y1 = data->current_y - (data->points[x][y] * data->z_offset);
	ttp->x2 = ttp->x1;
	ttp->y2 = ttp->y1;
	if (y != (data->width - 1))
	{
		ttp->x2 = data->next_x;
		ttp->y2 = data->next_y - (data->points[x][(y + 1)] * data->z_offset);
	}
}

void	adjust_for_z_x(t_data *data, t_two_points *ttp, int i)
{
	int	x;
	int	y;

	y = i / data->height;
	x = i % data->height;
	ttp->x1 = data->current_x;
	ttp->y1 = data->current_y - (data->points[x][y] * data->z_offset);
	ttp->x2 = ttp->x1;
	ttp->y2 = ttp->y1;
	if (x != (data->height - 1))
	{
		ttp->x2 = data->next_x;
		ttp->y2 = data->next_y - (data->points[x + 1][y] * data->z_offset);
	}
}
