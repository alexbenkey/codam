/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_lines.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/18 16:32:47 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/12/02 22:30:55 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	draw_lines(t_data *data)
{
	int				i;
	float			gradient;
	t_two_points	*ttp;

	ttp = malloc(sizeof(t_two_points));
	if (!ttp)
	{
		free_all(data);
		return ;
	}
	draw_vert_lines(data, ttp);
	re_init(data, ttp);
	draw_hor_lines(data, ttp);
	re_init(data, ttp);
	free(ttp);
}

void	draw_vert_lines(t_data *data, t_two_points *ttp)
{
	int		i;
	float	gradient;

	i = 0;
	while (i < ((data->height * data->width)))
	{	
		update_coordinates_x(data, i);
		adjust_for_z_x(data, ttp, i);
		gradient = get_gradient(ttp);
		draw_line(data, ttp, gradient);
		set_current_to_next(data);
		i++;
	}
}

void	draw_hor_lines(t_data *data, t_two_points *ttp)
{
	int		i;
	float	gradient;

	i = 0;
	while (i < ((data->height * data->width)))
	{	
		update_coordinates_y(data, i);
		adjust_for_z_y(data, ttp, i);
		gradient = get_gradient(ttp);
		draw_line(data, ttp, gradient);
		set_current_to_next(data);
		i++;
	}
}

void	draw_line(t_data *data, t_two_points *ttp, double gradient)
{
	if (!(ttp->x1 == ttp->x2 && ttp->y1 == ttp->y2))
	{
		if (gradient > 1 || gradient < -1.0)
			draw_line_y_base(data, ttp, gradient);
		else
			draw_line_x_base(data, ttp, gradient);
	}
}
